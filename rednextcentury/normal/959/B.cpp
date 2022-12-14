#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int best[1000000];
int a[1000000];
string s[1000000];
int main(){
    int n,m,k;
    cin>>n>>k>>m;
    for (int i=0;i<n;i++){
        cin>>s[i];
        best[i]=1000000000;
    }
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        while(x--)
        {
            int j;
            cin>>j;
            j--;
            mp[s[j]]=i;
            best[i]=min(best[i],a[j]);
        }
    }
    long long ret=0;
    for (int i=0;i<m;i++)
    {
        string s;
        cin>>s;
        ret+=best[mp[s]];
    }
    cout<<ret<<endl;
}