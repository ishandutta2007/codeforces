#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int prv[1000050], nxt[1000050];
bool in[1000050];

inline bool should(int i){
    return (prv[i] != -1 && str[prv[i]] != str[i]) ||
           (nxt[i] != n && str[nxt[i]] != str[i]);
}

inline bool remove(int i){
    int pn = prv[i], nn = nxt[i];
    prv[nn] = pn, nxt[pn] = nn;
}


int main(){
    int cnt = 0;

    fill(in, in + 1000050, true);
    getline(cin, str);
    n = str.length();
    vector<int> now;
    now.clear();
    vector<int> nxts;
    nxts.clear();

    for(int i = 0; i < n; i++){
        prv[i] = i - 1;
        nxt[i] = i + 1;
    }
    for(int i = 0; i < n; i++){
        if(should(i)) in[i] = 0, now.push_back(i);
    }
    while(!now.empty()){
        for(auto i : now){
            nxts.push_back(prv[i]);
            nxts.push_back(nxt[i]);
            remove(i);
            //cout << "remove : " << i << endl;
        }
        now.clear();
        for(auto i : nxts){
            if(i != -1 && i != n && in[i] && should(i)) {in[i] = 0, now.push_back(i);};
        }
        nxts.clear();
        cnt ++;
    }

    cout << cnt;
}