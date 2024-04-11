#include<iostream>
#include<set>
#include<map>
using namespace std;

int N, M, T;
int av[5005];
int gd[5005];
set<int> bp;
map<int, int> good;

int goodness(int val){
    if(good.count(val)) return good[val];
    int sf = -1;
    for(int q=2; q*q <= val; q++)
        if(val%q == 0){
            sf = q;
            break;
        }
    if(sf == -1) sf = val;
    if(bp.count(sf)) return good[val] = -1 + goodness(val/sf);
    else return good[val] = 1 + goodness(val/sf);
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> N >> M;
    for(int v=0; v<N; v++)
        cin >> av[v];
    for(int w=0; w<M; w++){
        cin >> T;
        bp.insert(T);
    }
    good[1] = 0;
    
    int ans = goodness(av[0]);
    gd[0] = av[0];
    for(int v=1; v<N; v++){
        gd[v] = gcd(gd[v-1], av[v]);
        ans += goodness(av[v]);
    }
    
    int div = 1;
    for(int p=N-1; p>=0; p--){
        if(goodness(gd[p]/div) < 0){
            ans -= (p+1)*goodness(gd[p]/div);
            div = gd[p];
        }
    }
    
    cout << ans << endl;
}