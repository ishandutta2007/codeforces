#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll N, s1, s2;
vector<ll> a, b;
bool lneg = false;

int cmp(){
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(a[i] < b[i]) return 1;
        if(a[i] > b[i]) return -1;
    }

    if(a.size() < b.size()) return 1;
    if(a.size() > b.size()) return -1;
    return 0;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        ll r; cin >> r;
        if(r < 0){
            s2 -= r;
            b.push_back(r);
        }
        else{
            s1 += r;
            a.push_back(-r);
        }
        lneg = r<0;
    }

    if(s1 != s2){
        if(s1 > s2) cout << "first" << endl;
        else cout << "second" << endl;
        return 0;
    }
    int c = cmp();
    if(c != 0){
        if(c == 1) cout << "first" << endl;
        else cout << "second" << endl;
        return 0;
    }

    cout << ((lneg)?"second":"first") << endl;
    return 0;
}