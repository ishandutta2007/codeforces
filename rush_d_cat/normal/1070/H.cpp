#include <iostream>
#include <cstring>
#include <map>
#include <set>
using namespace std;
int n; map<string,string> ans; map<string,int> cnt;

int main() {
    ios::sync_with_stdio(false); 
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s; cin>>s;
        int len=s.length();
        set<string> st;
        for(int i=0;i<len;i++) {
            for(int j=i;j<len;j++){
                string str="";
                for(int k=i;k<=j;k++)str+=s[k];
                ans[str]=s; st.insert(str);
            }
        }
        for(auto str: st) cnt[str]++;
    }
    int q; cin>>q;
    while(q--) {
        string s; cin>>s;
        cout<<cnt[s]<<" "<<(cnt[s]?ans[s]:"-")<<endl;
    }
}