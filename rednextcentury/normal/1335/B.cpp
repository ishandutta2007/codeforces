#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        string ret="";
        for (int i=0;i<n;i++){
            int cnt[26];
            for (int j=0;j<26;j++)cnt[j]=0;
            int num=0;
            for (int j=i-1;j>max(i-a,-1);j--){
                if (++cnt[ret[j]-'a']==1)num++;
            }
            char same, dif;
            for (int j=0;j<26;j++){
                if (cnt[j])same=char('a'+j);
                else dif = char('a'+j);
            }
            if (num<b)ret+=dif;
            else ret+=same;
        }
        cout<<ret<<endl;
    }
}