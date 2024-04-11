#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> a, d;

void push(int v){
    if(v * 2 < d.size() && d[v] != -1){
        d[v * 2] = d[v * 2 + 1] = d[v];
        d[v] = -1;
    }
}

void update(int v, int tl, int tr, int l, int r, int k){
    if(l >= tr || r <= tl)return;
    if(l >= tl && r <= tr){
        d[v] = k;
    }
    else{
        push(v);
        int m = (l + r) / 2;
        update(v * 2, tl, tr, l, m, k);
        update(v * 2 + 1, tl, tr, m, r, k);
    }

}

void make(int v, int l, int r){
    if(d[v] != -1){
        for(int i = l; i < r; i++)a[i] = d[v];
    }
    else{
        int m = (l + r) / 2;
        make(v * 2, l, m);
        make(v * 2 + 1, m, r);
    }
}

/*int get(int v, int tl, int tr, int l, int r){
    if(l <= tl && r >= tr){
        if(d[v] != -1)return d[v];

    }
    if()
}*/

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> b(n);
    for(int i = 0; i < n; i++)cin >> b[i];

    vector<pair<int, int> > lr(q + 1, make_pair(n, 0));
    for(int i = 0; i < n; i++){
        lr[b[i]].first = min(lr[b[i]].first, i);
        lr[b[i]].second = max(lr[b[i]].second, i + 1);
    }

    int ind0 = -1;
    for(int i = 0; i < n; i++)
        if(b[i] == 0)ind0 = i;

    for(int i = q; i <= q; i++)
        if(lr[i].first > lr[i].second){

            if(ind0 > -1){
                lr[i].first = ind0;
                lr[i].second = ind0 + 1;
                break;
            }
            else{
                cout << "NO";
                return 0;
            }
        }

    a = vector<int>(2 * n, 1);
    d = vector<int>(4 * n, -1);

    int k = 1;
    for(; k < n; k *= 2);

    update(1, 0, k, 0, k, 1);
    for(int i = 2; i <= q; i++)
        if(lr[i].first < lr[i].second)update(1, lr[i].first, lr[i].second, 0, k, i);

    /*for(int i = 1; i <= k; i *= 2){
        for(int j = 0; j < i; j++)cout << d[i + j] << ' ';
        cout << endl;
    }
    */
    make(1, 0, k);

    bool flag = false;
    for(int i = 0; i < n; i++)if(!(b[i] == 0 || a[i] == b[i]))flag = true;

    if(flag)cout << "NO";
    else {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)cout << a[i] << ' ';
    }
}