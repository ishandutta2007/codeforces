#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main() {    
    int T;
    scanf("%lld",&T);
    while (T--) {
        string t;
        cin>>t;
        int vis[26]={},cnt[26]={}; 
       // int pos=t.length()-1; 
        int len=t.length();
        string rk="";
        int o=0,num=0; 
        for (int i=0;i<26;i++) vis[i]=-1,cnt[i]=0; 
        for (int i=len-1;i>=0;i--) {
            if (vis[t[i]-'a']==-1) {
                rk+=t[i];
                vis[t[i]-'a']=o;
                o++; num++;
            }
            cnt[t[i]-'a']++; 
        }
        int ok=1; 
        int mx=0; 
        for (int i=0;i<26;i++) {
            if (vis[i]==-1) continue ;
            if (cnt[i]%(num-vis[i])!=0) {
                ok=0; break ; 
            }
            int cc=cnt[i]/(num-vis[i]);
           // cout<<cc<<'\n'; 
            for (int j=0;j<len;j++) {
                if (t[j]-'a'==i) {
                    cc--; 
                    if (cc==0) {
                        mx=max(mx,j); 
                        break ; 
                    }
                }
            }
        }
        string s="";
        for (int i=0;i<=mx;i++) {
            s+=t[i]; 
        }
        //cout<<s<<'\n'; 
        string anss=s; 
        string tt=""; 
        for (int i=1;i<=num;i++) {
            tt+=s;
            if (tt.length()>t.length()) {
                ok=0; break ; 
            }
            string tmps="";
            for (int j=0;j<s.length();j++) {
                if (s[j]!=rk[num-i]) tmps+=s[j]; 
            }
            s=tmps;
        }
      //  cout<<rk<<'\n'; 
      //  cout<<tt<<'\n'; 
        for (int i=0;i<tt.length();i++) {
            if (tt[i]!=t[i]) {
                ok=0; break ; 
            }
        }
        if (!ok) puts("-1");
        else {
            cout<<anss<<' ';
            for (int i=num-1;i>=0;i--) cout<<rk[i]; 
            cout<<'\n'; 
        }
    }
    return 0; 
}