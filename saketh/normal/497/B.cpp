#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100000;

int N, P1, P2;
int res[MAXN+5];
int scr[2][MAXN+5];
int rch[2][MAXN+5];

vector<pair<int, int> > ans;

void att(int t){
    int i = 0;
    int s1 = 0, s2 = 0;
    int last = -1;

    while(i<N){
        int p1r = MAXN+1, p2r = MAXN+1;
        if(scr[0][i] + t <= N) p1r = rch[0][scr[0][i]+t];
        if(scr[1][i] + t <= N) p2r = rch[1][scr[1][i]+t];
    
        int rch = min(p1r, p2r);
        if(rch == MAXN+1) break;

        if(p1r < p2r){ s1++; last = 1; }
        else{ s2++; last = 2; }

        i = rch;
    }

    if(i != N) return;
    if(s1 == s2) return;
    if(s1 < s2 && last == 1) return;
    if(s2 < s1 && last == 2) return;

    ans.push_back(make_pair(max(s1, s2), t));
}

int main(){
    for(int i=1; i<=MAXN; i++)
        rch[0][i] = rch[1][i] = MAXN+1;

    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> res[i];
        if(res[i] == 2){
            P2++;
            rch[1][P2] = i+1;
        }
        else{
            P1++;
            rch[0][P1] = i+1;
        }

        scr[0][i+1] = P1;
        scr[1][i+1] = P2;
    }

    for(int t=1; t<=N; t++) att(t);
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";
    cout.flush();
    return 0;
}