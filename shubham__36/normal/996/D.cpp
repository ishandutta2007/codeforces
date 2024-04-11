#include <iostream>

using namespace std;

void f(int a[], int b[], int j, int n)
{
    int temp1 = a[j], temp2=a[j];
    a[j]=b[j];
    for(int i=j+1;i<2*n;i++){
        if(a[i]==b[j]) {a[i]= temp1; break;}
        temp1 = a[i];
        a[i]= temp2;
        temp2 = temp1;
    }
    for(int i=j/2;i<n;i++){
        b[2*i]=a[2*i];
        b[2*i+1]=a[2*i];
    }
}

int g(int a[],int j,int n)
{
    for(int i=j+1;i<2*n;i++){
        if(a[i]==a[j-1]) return (i-j);
    }
}

int main()
{
    int n,ans=0;
    cin >> n;
    int a[2*n],b[2*n];
    for(int i=0;i<2*n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        b[2*i]=a[2*i];
        b[2*i+1]=a[2*i];
    }
    for(int i=0;i<2*n;i++){
        if(a[i]!=b[i]) {ans+=g(a,i,n); f(a,b,i,n);}
    }
    cout << ans;
    return 0;
}