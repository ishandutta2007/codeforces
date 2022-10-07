#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<ll,ll>, ll> P,N;
ll pos, neg;
ll A[100009],B[100009],C[100009];
struct vec{
    ll x,  y;
};
ll half(vec a){
    if(a.x > 0) return 0;
    if(a.x == 0 && a.y > 0) return 0;
    return 1;
}
bool operator < (vec a, vec b){
  if(half(a) < half(b))  return 1;
  if(half(a) > half(b)) return 0;
  return (long double)a.x * b.y < (long double)a.y * b.x;

}
bool operator == (vec a, vec b){
  return a.x == b.x && a.y == b.y;

}
bool operator <= (vec a, vec b){
  return a < b || a == b;

}
bool ha(vec a, vec b){
     return (long double)a.x * b.y < (long double)a.y * b.x;
}
main(){
    ll x, y, z;
    cin >> x >> y >> z;
    int typ = 1;
    if(x != 0) typ = 2, swap(x,z); else
    if(y != 0) typ = 3, swap(y,z);
    ll u= 0, zer = 0, sum = 0, huh = 0, dif = 0;
    multiset<vec> S;
    ll q;
    cin>>q;
    for(ll i = 0; i <= q; i++){
        if(i){
            if(zer) cout<<1<<endl;
            else if(sum) cout << 2 << endl;
            else if(!huh && dif >= 3) cout<<3<<endl;
            else cout<<0<<endl;
        }
        if(i == q) break;
        char T;
        cin >> T;
        if(T == 'A'){
            ++u;
            cin>> A[u] >> B[u]>> C[u];
            if(typ == 2) swap(A[u], C[u]);
            if(typ == 3) swap(B[u], C[u]);
            ll X = A[u] * z - C[u] * x;
            ll Y = B[u] * z - C[u] * y;
            if(X == 0 && Y == 0){
                zer++;
                continue;
            }
            ll d = __gcd(X, Y);
            d = abs(d);
            X /= d;
            Y /= d;
            vec V = {X,Y};
            if(S.size()){
                if(S.find(V) == S.end()){
                    dif ++;
                    auto it = S.lower_bound(V);
                    if(it == S.end()) it = S.begin();
                    vec N = *it;
                    if(it == S.begin()) it = --S.end();
                    else it --;
                    vec P = *it;
                    if(ha(V, P)) huh ++;
                    if(ha(N, V)) huh ++;
                    if(ha(N, P)) huh --;
                }
            }
            else dif++;
            S.insert(V);
            P[make_pair(X,Y)] ++;
                if(P[make_pair(X,Y)] == 1 && P[make_pair(-X,-Y)] > 0)
                    sum++;
        }
        else{
            ll w;
            cin >> w;

            ll X = A[w] * z - C[w] * x;
            ll Y = B[w] * z - C[w] * y;
            if(X == 0 && Y == 0){
                zer--;
                continue;
            }
            ll d = __gcd(X, Y);
            d = abs(d);
            X /= d;
            Y /= d;
            vec V = {X,Y};
            S.erase(S.find(V));
            if(S.size()){

                if(S.find(V) == S.end()){
                    dif --;
                    auto it = S.lower_bound(V);
                    if(it == S.end()) it = S.begin();
                    vec N = *it;
                    if(it == S.begin()) it = --S.end();
                    else it --;
                    vec P = *it;
                    if(ha(V,P)) huh --;
                    if(ha(N, V)) huh --;
                    if(ha(N,P)) huh ++;
                }
            }
            else dif--;
             P[make_pair(X,Y)] --;

                if(P[make_pair(X,Y)] == 0 && P[make_pair(-X,-Y)] > 0)
                    sum--;
        }
    }
}