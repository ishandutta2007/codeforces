#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int num=0;

bool search(long long int temp,long long int a[],long long int b[],long long int i,long long int l,long long int u)
{
    if(l>=u){
        return false;
    }
    if(a[l]>temp){
        return false;
    }
    if(a[u-1]<temp){
        return false;
    }
    long long int k=(l+u)/2;
    //cout << k << endl;
    if(a[k]==temp && k!=i){
        if(b[k]==0){
        b[k]=1;
        num++;
    }
    return true;
    }
    if(a[k]==temp){
        if(k+1<u && a[k+1]==temp){
            if(b[k+1]==0){
        b[k+1]=1;
        num++;
        }
        return true;
        }
        else if(k-1>=l && a[k-1]==temp){
            if(b[k-1]==0){
        b[k-1]=1;
        num++;
        }
        return true;
        }
        return false;
    }
    else if(a[k]>temp){
        return search(temp,a,b,i,l,k);
    }
    else if(a[k]<temp){
        return search(temp,a,b,i,k+1,u);
    }
}

int main()
{
    long long int n;
    cin >> n;
    long long int a[n],b[n],c[31],temp;
    for(long long int i=0;i<n;i++){
        cin >> a[i];
        b[i]=0;
    }
    for(long long int i=0;i<31;i++){
        c[i]=pow(2,i+1);
    }
    sort(a,a+n);
    for(long long int i=0;i<n;i++){
        if(b[i]==1) continue;
        else {for(long long int j=0;j<31;j++){
        temp=c[j]-a[i];
        if(temp<1) continue;
        else {
            if(search(temp,a,b,i,0,n)){
            b[i]=1;
            num++;
            break;
            }
        }
        }
        //cout << num << endl << endl;
        }
    }
    cout << n-num << endl;
    return 0;
}