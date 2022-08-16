#include <iostream>
#include <algorithm>

using namespace std;

long long int n;

long long int msearch(long long int v,long long int c[],long long int l,long long int u)
{
    if((l+u)%2){
        if(c[l]==v) return l;
        else l++;
    }
    if(c[(l+u)/2]==v) return (l+u)/2;
    else if(c[(l+u)/2]>v) return msearch(v,c,l,(l+u)/2);
    else return msearch(v,c,(l+u)/2,u);
}

int main()
{
    long long int prev,j1,j2,sum=0;
    cin >> n;
    long long int a[n],b[n],c[2*n],d[2*n],e[n+1];
    for(long long int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        c[2*i]=a[i];
        c[2*i+1]=b[i]+1;
        d[2*i]=0;
        d[2*i+1]=0;
    }
    for(long long int i=0;i<n+1;i++){
        e[i]=0;
    }
    sort(c,c+2*n);
    for(long long int i=0;i<n;i++){
        j1=msearch(a[i],c,0,2*n-1);
        j2=msearch(b[i]+1,c,0,2*n-1);
        d[j1]++;
        d[j2]--;
    }
    prev=c[0];
    sum+=d[0];
    for(long long int i=1;i<2*n;i++){
        if(prev!=c[i]){
            e[sum] += c[i]-prev;
            sum+=d[i];
            prev=c[i];
        }
        else{
            sum+=d[i];
        }
    }
    for(long long int i=1;i<n+1;i++){
        cout << e[i] << " ";
    }
    return 0;
}