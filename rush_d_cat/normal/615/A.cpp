#include<iostream>
using namespace std;
bool ok[100+2];
int main()
{
    int n,m;
    cin>>n>>m;
    memset(ok,false,sizeof(ok));
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        for(int j=1;j<=x;j++){
            int y;cin>>y;
            ok[y]=true;
        }
    }
    int res=0;
    for(int i=1;i<=m;i++) res+=ok[i];
    if(res==m) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}