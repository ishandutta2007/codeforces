#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[6];
int b[6];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x;
    cin>>x;
    for (int i=0;i<6;i++){
        a[i] = (((1<<(6-i-1))&x)>0);
    }
    b[0]=a[0];
    b[5]=a[1];
    b[3]=a[2];
    b[2]=a[3];
    b[4]=a[4];
    b[1]=a[5];
    int ret=0;
    for (int i=0;i<6;i++){
        if (b[i]==1){
            ret+=(1<<(6-i-1));
        }
    }
    cout<<ret<<endl;
}
//1 6 4 3 5 2