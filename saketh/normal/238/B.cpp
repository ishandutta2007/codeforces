#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MAXN = 100005;

int N, H;
int val[MAXN];
vector<int> all;

int eval(vector<int> s1, vector<int> s2){
    int lo = 1e9, hi = 0;
    
    for(int a : s1)
        for(int b : s2){
            lo = min(lo, a+b+H);
            hi = max(hi, a+b+H);
        }

    if(s1.size() >= 2){
        int v1 = s1[0] + s1[1];
        int v2 = s1[s1.size()-2] + s1[s1.size()-1];
        lo = min(lo, v1);
        hi = max(hi, v2);
    }

    if(s2.size() >= 2){
        int v1 = s2[0] + s2[1];
        int v2 = s2[s2.size()-2] + s2[s2.size()-1];
        lo = min(lo, v1);
        hi = max(hi, v2);
    }

    return hi - lo;
}


int main(){
    setup();
    cin >> N >> H; 
    for(int i=0; i<N; i++){
        cin >> val[i];    
        all.push_back(val[i]);
    }

    sort(all.begin(), all.end());

    if(all.size() < 3){
        cout << 0 << endl;
        for(int i=0; i<N; i++)
            cout << 1 << " ";
        cout << endl;
        return 0;
    }

    int lm = -1, gp = 1e9;

    for(int m=0; m<4; m++){
        int lo = 1e9;
        int hi = 0;

        bool op2 = !!(m&1);
        bool op3 = !!(m&2);

        vector<int> top, bot;
        top.push_back(all[0]);
        if(op2) bot.push_back(all[1]);
        else top.push_back(all[1]);
       
        if(op3) {
            bot.push_back(all[2]);
            if(all.size() >= 4) bot.push_back(all.back());
            if(all.size() >= 5) bot.push_back(all[all.size()-2]);
        } else {
            top.push_back(all[2]);
            if(all.size() >= 4) top.push_back(all.back());
            if(all.size() >= 5) top.push_back(all[all.size()-2]);
        }

        int res = eval(top, bot);
        if(res < gp){
            gp = res;
            lm = m;
        }
    }

    cout << gp << endl;
    int op2 = 1 + !!(lm&1);
    int op3 = 1 + !!(lm&2);

    bool p1 = false, p2 = false;
    for(int i=0; i<N; i++){
        if(val[i] == all[0] && !p1){ cout << "1 "; p1 = true; }
        else if(val[i] == all[1] && !p2){ cout << op2 << " "; p2 = true; }
        else cout << op3 << " ";
    }    
    cout << endl;
}