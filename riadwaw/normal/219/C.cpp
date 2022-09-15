#include <iostream>
#include <string>
using namespace std;
int cnt[256];
typedef long long li;
void solve();
int main(){

    ios_base::sync_with_stdio(false);
solve();
return 0;
}


int diff(const string& a, const string& b){
    int res = 0;
    for(int i = 0; i < a.length(); ++i){
        if(a[i] != b[i])
            ++res;
    }
    return res;
}

char no(char a){
    return (a=='A') ? 'B' : 'A';
}

char no(char a, char b){
    //cout<<a<<' '<<b<<endl;
    if(a>b)
        swap(a,b);
    if(a == 'A' && b =='B'){
        return 'C';

    }
    if(a=='A')
        return 'B';
    return 'A';
}
string s1, s2;
void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    for(int i = 0; i < n;++i){
        s1+="AB";
        s2+="BA";
    }
    if(k == 2){
        if(diff(s, s1) < diff(s, s2)){
            cout<<diff(s, s1)<<endl;
            cout<<s1.substr(0, s.length());
        }
        else{
            cout<<diff(s, s2)<<endl;
            cout<<s2.substr(0, s.length());
        }
        return;
    }

    char prev;
    int groupstart = 0;

    int ans = 0;
    for(int i = 0; i<= n; ++i){
        if(i == n || s[i] != s[groupstart]){
            int len = i - groupstart;
            ans += len/2;
            if(len % 2){
                char c = no(s[i-1]);
                for(int t = groupstart + 1; t< i ;t+= 2){
                    s[t] = c;
                }
            }

            else{
                char c = no(s[i - 1], (groupstart == 0)?'Z' + 1:s[groupstart - 1]);
                //cout<<c;
                for(int t = groupstart; t< i ;t+=2){
                    s[t] = c;
                }
            }


            groupstart = i;
        }
    }

    cout<<ans<<endl<<s;
}