#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[100];
string h;
string s;
bool check(){
    int cnt2[26];
    for (int i=0;i<26;i++)cnt2[i]=cnt[i];
    for (auto x:s){
        if (cnt2[x-'a']==0)return 0;
        cnt2[x-'a']--;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        cin>>s>>h;
        if (h.size()<s.size()){
            cout<<"NO"<<endl;
        } else {
            for (int i=0;i<s.size();i++)cnt[h[i]-'a']++;
            bool sol=check();
            int n = s.size();
            for (int i=s.size();i<h.size();i++) {
                cnt[h[i-n]-'a']--;
                cnt[h[i]-'a']++;
                if (check())sol=1;
            }
            if (sol)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}