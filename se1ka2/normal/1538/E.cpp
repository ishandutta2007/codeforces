#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll l[200005], r[200005], o[200005], h[200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> mp;
        map<string, string> fl;
        ll last = 0;
        int k = 0;
        while(n--){
            string x;
            cin >> x;
            if(!mp.count(x)) mp[x] = k++;
            string p;
            cin >> p;
            if(p == ":="){
                l[mp[x]] = r[mp[x]] = o[mp[x]] = h[mp[x]] = 0;
                string s;
                cin >> s;
                fl[x] = "";
                fl[x] += s[0];
                fl[x] += s.back();
                int m = s.size();
                bool f = true;
                if(s[0] != 'a' && s[0] != 'h') f = false;
                int c = 0;
                for(int i = 0; i < m - 1; i++){
                    if(s.substr(i, 2) != "ha" && s.substr(i, 2) != "ah"){
                        if(f){
                            if(s[0] == 'a') l[mp[x]] = 1 + c * 2;
                            else l[mp[x]] = c * 2;
                            f = false;
                        }
                        else{
                            h[mp[x]] += max(0, c - 1);
                        }
                        c = 0;
                    }
                    if(s.substr(i, 2) == "ha") c++;
                }
                if(f) o[mp[x]] = m;
                else if(s[m - 1] == 'h') r[mp[x]] = 1 + c * 2;
                else r[mp[x]] = c * 2;
            }
            else{
                string a, plus, b;
                cin >> a >> plus >> b;
                if(o[mp[a]]){
                    if(o[mp[b]]){
                        if(fl[a][1] != fl[b][0]){
                            l[mp[x]] = r[mp[x]] = h[mp[x]] = 0;
                            o[mp[x]] = o[mp[a]] + o[mp[b]];
                        }
                        else{
                            if(fl[a][1] == 'a') l[mp[x]] = o[mp[a]], r[mp[x]] = o[mp[b]] - 1;
                            else l[mp[x]] = o[mp[a]] - 1, r[mp[x]] = o[mp[b]];
                            h[mp[x]] = o[mp[x]] = 0;
                        }
                    }
                    else{
                        if(fl[a][1] != fl[b][0]){
                            l[mp[x]] = o[mp[a]] + l[mp[b]];
                            r[mp[x]] = r[mp[b]];
                            o[mp[x]] = 0;
                            h[mp[x]] = h[mp[b]];
                        }
                        else{
                            h[mp[x]] = h[mp[b]] + max(0ll, l[mp[b]] / 2 - 1);
                            if(fl[a][1] == 'h') l[mp[x]] = o[mp[a]] - 1;
                            else l[mp[x]] = o[mp[a]];
                            r[mp[x]] = r[mp[b]];
                            o[mp[x]] = 0;
                        }
                    }
                }
                else{
                    if(o[mp[b]]){
                        if(fl[a][1] != fl[b][0]){
                            l[mp[x]] = l[mp[a]];
                            r[mp[x]] = r[mp[a]] + o[mp[b]];
                            o[mp[x]] = 0;
                            h[mp[x]] = h[mp[a]];
                        }
                        else{
                            h[mp[x]] = h[mp[a]] + max(0ll, r[mp[a]] / 2 - 1);
                            l[mp[x]] = l[mp[a]];
                            if(fl[b][0] == 'a') r[mp[x]] = o[mp[b]] - 1;
                            else r[mp[x]] = o[mp[b]];
                            o[mp[x]] = 0;
                        }
                    }
                    else{
                        if(fl[a][1] != fl[b][0]){
                            h[mp[x]] = h[mp[a]] + h[mp[b]] + max(0ll, (r[mp[a]] + l[mp[b]]) / 2 - 1);
                            l[mp[x]] = l[mp[a]];
                            r[mp[x]] = r[mp[b]];
                            o[mp[x]] = 0;
                        }
                        else{
                            h[mp[x]] = h[mp[a]] + h[mp[b]] + max(0ll, r[mp[a]] / 2 - 1) + max(0ll, l[mp[b]] / 2 - 1);
                            l[mp[x]] = l[mp[a]];
                            r[mp[x]] = r[mp[b]];
                            o[mp[x]] = 0;
                        }
                    }
                }
                string temp;
                temp += fl[a][0];
                temp += fl[b][1];
                fl[x] = temp;
            }
            if(o[mp[x]]){
                if(fl[x][0] == 'a') last = max(0ll, (o[mp[x]] - 1) / 2 - 1);
                else last = max(0ll, o[mp[x]] / 2 - 1);
            }
            else last = h[mp[x]] + max(0ll, r[mp[x]] / 2 - 1) + max(0ll, l[mp[x]] / 2 - 1);
        }
        cout << last << endl;
    }
}