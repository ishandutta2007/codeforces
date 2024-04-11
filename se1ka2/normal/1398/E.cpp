#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    int n;
    cin >> n;
    set<P> lar, sm;
    ll l = 0, s = 0;
    int f = 0;
    while(n--){
        int tp;
        ll d;
        cin >> tp >> d;
        if(d > 0){
            if(tp == 0){
                lar.insert(P(d, tp));
                l += d;
                f++;
                P p = *lar.begin();
                lar.erase(p);
                l -= p.first;
                if(p.second == 0) f--;
                sm.insert(p);
                s += p.first;
            }
            else{
                sm.insert(P(d, tp));
                s += d;
                P p = *sm.rbegin();
                sm.erase(p);
                s -= p.first;
                if(p.second == 0) f++;
                lar.insert(p);
                l += p.first;
            }
        }
        else{
            d = -d;
            if(tp == 0){
                if(lar.find(P(d, tp)) != lar.end()){
                    lar.erase(P(d, tp));
                    l -= d;
                    f--;
                    P p = *sm.rbegin();
                    sm.erase(p);
                    s -= p.first;
                    if(p.second == 0) f++;
                    lar.insert(p);
                    l += p.first;
                }
                else{
                    sm.erase(P(d, tp));
                    s -= d;
                }
            }
            else{
                if(lar.find(P(d, tp)) != lar.end()){
                    lar.erase(P(d, tp));
                    l -= d;
                }
                else{
                    sm.erase(P(d, tp));
                    s -= d;
                    P p = *lar.begin();
                    lar.erase(p);
                    l -= p.first;
                    if(p.second == 0) f--;
                    sm.insert(p);
                    s += p.first;
                }
            }
        }
        if(f == 0){
            if(sm.empty() && lar.empty()){
                cout << 0 << endl;
            }
            else if(sm.empty()){
                cout << l * 2 - lar.begin()->first << endl;
            }
            else if(lar.empty()){
                cout << s << endl;
            }
            else{
                cout << l * 2 + s - (lar.begin()->first - sm.rbegin()->first) << endl;
            }
        }
        else{
            cout << l * 2 + s << endl;
        }
    }
}