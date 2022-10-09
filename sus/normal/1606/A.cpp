#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int countFreq(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    int res = 0;
   
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i+j] != pat[j])
                break;
  
        if (j == M) 
        {
           res++;
           j = 0;
        }
    }
    return res;
    cout << res << ln;
}
 
void solve(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ab = 0;
        int ba = 0;
        //if(s.size()==1){
        //    cout << s << ln;
        
        //else {
        ab = countFreq("ab", s);
        ba = countFreq("ba", s);
        //cout << ab << sp << ba << ln;
        if(s[0]==s[s.size()-1]){
            cout << s << ln;
        }
        else{
            if(s[0]=='a' && s[s.size()-1]=='b') s[s.size()-1]='a';
            if(s[0]=='b' && s[s.size()-1]=='a') s[s.size()-1]='b';
            cout << s << ln;
        }
        
        
    }
}

int main() {
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    fastIO();
    solve();
}