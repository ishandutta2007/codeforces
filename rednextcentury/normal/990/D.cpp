#include<bits/stdc++.h>
using namespace std;
#define ll long long
int adj[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    if (n==1 && a==1 && b==1) {
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    if (n<=3 && a==1 && b==1) {
        printf("NO\n");
        return 0;
    }
    if (a==1){
        printf("YES\n");
        for (int i=2;i<=n-b+1;i++)adj[i][i-1]=adj[i-1][i]=1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j)adj[i][j]=1;
                printf("%d",1-adj[i][j]);
            }
            printf("\n");
        }
    } else if (b==1){
        printf("YES\n");
        for (int i=2;i<=n-a+1;i++)adj[i][i-1]=adj[i-1][i]=1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++)
                printf("%d",adj[i][j]);
            printf("\n");
        }
    } else printf("NO\n");
}