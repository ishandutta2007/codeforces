#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, V, T, C, A;
vector<pair<int, int> > one, two;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> V;
    for(int i=0; i<N; i++){
        cin >> T >> C;
        if(T==1) one.emplace_back(C, i);
        else two.emplace_back(C, i);
    }

    sort(one.begin(), one.end());
    reverse(one.begin(), one.end());
    sort(two.begin(), two.end());
    reverse(two.begin(), two.end());

    int best = 0, bi = 0, bj = 0;
    int capa = 0, i = 0, j = 0, use = 0;

    while(i<one.size() && use+1<=V){
        capa += one[i++].first;
        use++;
    }

    for(int ii=i; ii>=0; ii--){
        if(i>ii){ use--; i--; capa -= one[i].first; }
        while(j<two.size() && use+2<=V){
            capa += two[j++].first;
            use+=2;
        }
        if(capa > best){ best = capa; bi = ii; bj = j; }
    }

    cout << best << "\n";
    for(int k=0; k<bi; k++) cout << one[k].second+1 << "\n";
    for(int k=0; k<bj; k++) cout << two[k].second+1 << "\n";
    cout.flush();
    return 0;
}