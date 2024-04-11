#include<bits/stdc++.h>
using namespace std;
#define ll long long
int best[1001][1001];
int L[1000000];
int R[1000000];
int len[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ret=0;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        L[i]=s[0]-'a';
        R[i]=s.back()-'a';
        if (L[i]==R[i])ret=max(ret,(int)s.size());
        len[i]=s.size();
    }
    for (int i=0;i<26;i++)for (int j=0;j<26;j++)best[i][j]=-1e9;
    for (int i=1;i<=n;i++){
        ret=max(ret, best[R[i]][L[i]]+len[i]);
        int tmp[26];

        for (int j=0;j<26;j++)tmp[j]=0;
        for (int j=0;j<26;j++){
            tmp[j]=max(best[j][R[i]], best[j][L[i]]+len[i]);
        }
        for (int j=0;j<26;j++){
            best[j][R[i]]=tmp[j];
        }

        best[L[i]][R[i]]=max(best[L[i]][R[i]], len[i]);

    }
    cout<<ret<<endl;
}