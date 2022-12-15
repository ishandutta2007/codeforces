#include <bits/stdc++.h>

using namespace std;

int a[6] = {4, 8, 15, 16, 23, 42};
int adj[6][6];

pair<int, int> ask_query(int i, int j){
    cout << "? " << i << " " << j << endl;
    fflush(stdout);
    int x;

    cin >> x;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(adj[i][j] == x){
                return {a[i], a[j]};
            }
        }
    }

    return {-1, -1};
}

int fce(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first || p1.first == p2.second){
        return p1.first;
    }
    if(p1.second == p2.first || p1.second == p2.second){
        return p1.second;
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(i == j){
                continue;
            }

            adj[i][j] = a[i] * a[j];
        }
    }

    pair<int, int> p1 = ask_query(1, 2), p2 = ask_query(3, 4);
    pair<int, int> p3 = ask_query(1, 3), p4 = ask_query(1, 5);

    int b[6];

    b[0] = fce(p1, p3);

    if(b[0] == p1.first){
        b[1] = p1.second;
    }
    else{
        b[1] = p1.first;
    }

    b[2] = fce(p2, p3);

    if(b[2] == p2.first){
        b[3] = p2.second;
    }
    else{
        b[3] = p2.first;
    }

    //cout << p4.first << " " << p4.second << endl;

    if(b[0] == p4.first){
        b[4] = p4.second;
    }
    else{
        b[4] = p4.first;
    }

    int mult = a[0] + a[1] + a[2] + a[3] + a[4] + a[5];

    mult -= b[0] + b[1] + b[2] + b[3] + b[4];

    b[5] = mult;

    cout << "!";

    for(int i = 0; i < 6; i++){
        cout << " " << b[i];
    }
    cout << endl;
    fflush(stdout);

    return 0;
}