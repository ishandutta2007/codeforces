#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int winner(int a, int b) {
    cout<<"? "<<a<<" "<<b<<endl;
    int next;cin>>next;
    if (next==0) return -1;
    if (next==1) return a;
    return b;
}

void solve(vector<int> &alive) {
    if (alive.size()==1) {
        cout<<"! "<<alive[0]<<endl;
        return;
    }
    if (alive.size()==2) {
        int winnera=winner(alive[0], alive[1]);
        cout<<"! "<<winnera<<endl;
        return;
    }
    vector<int> nextAlive;
    for (int start=0; start<alive.size(); start+=4) {
        int a=alive[start+0];
        int b=alive[start+1];
        int c=alive[start+2];
        int d=alive[start+3];
        int acWinner=winner(a,c);
        if (acWinner==-1) {
            //ac must both be losers
            nextAlive.push_back(winner(b,d));
        }
        else if (acWinner==a) {
            nextAlive.push_back(winner(a, d));
        }
        else {
            nextAlive.push_back(winner(b, c));
        }
    }
    solve(nextAlive);
}

int main() {   
    int T; cin>>T;
    for (int tt=0; tt<T; tt++) {
        int n;cin>>n;
        vector<int> alive;
        for (int i=1; i<=1<<n; i++)
            alive.push_back(i);
        solve(alive);
    }
    return 0;
}