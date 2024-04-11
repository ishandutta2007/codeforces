#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MAX_N 28
int t;
int k;
string s, a, b;
int temp[MAX_N];
int inv[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    F0R(_, t){
        cin >> k >> s >> a >> b;

        memset(temp, -1, sizeof temp);
        memset(inv, -1, sizeof inv);

        bool works = true;
        bool same = true;

        //stick to a until we find one that can be better
        F0R(i, s.length()){
            int ch = s[i]-'a';
            
            int aCh = a[i]-'a';
            int bCh;
            if(same) bCh = b[i]-'a';
            else bCh = k;

            if(temp[ch] != -1){
                int newCh = temp[ch];
                if(newCh < aCh || (aCh != bCh && newCh == bCh) || newCh > bCh){
                    //cout << "NO\n";
                    works = false;
                    //cout << "fail 1\n";
                    break; //we will take care of =b[i] in part two
                } else if(newCh > aCh){
                    //cout << "succ 1\n";
                    //works = true; //success!
                    break;
                } else{
                    if(aCh != bCh) same = false;
                    continue;
                }
            }

            if(bCh-aCh > 1){
                bool good = false;
                FOR(j, aCh+1, bCh-1){
                    if(inv[j] == -1){
                        temp[ch] = j;
                        inv[j] = ch;
                        good = true;
                        //cout << "succ 2\n";
                        break;
                    }
                }
                if(good) break;
            }

            if(inv[aCh] != -1){
                works = false;
                //cout << "fail 2\n";
                break;
            }

            temp[ch] = aCh;
            inv[aCh] = ch;

            if(aCh != bCh) same = false;
        }

        if(works){
            vi badT;
            vi badCh;
            F0R(i, k){
                if(temp[i] == -1) badT.pb(i);
                if(inv[i] == -1) badCh.pb(i);
            }

            F0R(i, badT.size()){
                int t = badT[i];
                int ch = badCh[i];

                temp[t] = ch;
                inv[ch] = t;
            }

            cout << "YES\n";
            F0R(i, k){
                cout << (char)('a'+temp[i]);
            }

            cout << "\n";
            continue;
        }
        
        //ok let's do the same thing

        memset(temp, -1, sizeof temp);
        memset(inv, -1, sizeof inv);

        works = true;
        same = true;

        //stick to b until we find one that can be better
        F0R(i, s.length()){
            int ch = s[i]-'a';
            
            int aCh;
            int bCh = b[i]-'a';

            if(same) aCh = a[i]-'a';
            else aCh = -1;

            if(temp[ch] != -1){
                int newCh = temp[ch];
                if((aCh != bCh && newCh == aCh) || newCh < aCh || newCh > bCh){
                    //cout << "NO\n";
                    works = false;
                    //cout << "fail 1\n";
                    break;
                } else if(newCh < bCh){
                    //cout << "succ 1\n";
                    //works = true; //success!
                    break;
                } else{
                    if(aCh != bCh) same = false;
                    continue;
                }
            }

            if(bCh-aCh > 1){
                bool good = false;
                FOR(j, aCh+1, bCh-1){
                    if(inv[j] == -1){
                        temp[ch] = j;
                        inv[j] = ch;
                        good = true;
                        //cout << "succ 2\n";
                        break;
                    }
                }
                if(good) break;
            }

            if(inv[bCh] != -1){
                works = false;
                //cout << "fail 2\n";
                break;
            }

            temp[ch] = bCh;
            inv[bCh] = ch;

            if(aCh != bCh) same = false;
        }

        if(works){
            vi badT;
            vi badCh;
            F0R(i, k){
                if(temp[i] == -1) badT.pb(i);
                if(inv[i] == -1) badCh.pb(i);
            }

            F0R(i, badT.size()){
                int t = badT[i];
                int ch = badCh[i];

                temp[t] = ch;
                inv[ch] = t;
            }

            cout << "YES\n";
            F0R(i, k){
                cout << (char)('a'+temp[i]);
            }
            cout << "\n";
        } else{
            cout << "NO\n";
        }
    }

    return 0;
}