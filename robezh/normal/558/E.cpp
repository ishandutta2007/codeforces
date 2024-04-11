#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,q,k,a,b;
string s;

int lazy[30][4 * N];
int dat[30][4 * N];

void propagate(int i, int x, int l, int r) {
    int mid = (l + r) / 2;

    if(lazy[i][x] == -1){
        dat[i][x*2+1] = dat[i][x*2+2] = 0;
        lazy[i][x*2+1] = lazy[i][x*2+2] = -1;
        lazy[i][x] = 0;
    }
    else{
        dat[i][x*2+1] = mid - l + 1;
        dat[i][x*2+2] = r - mid;

        lazy[i][x*2+1] = lazy[i][x*2+2] = 1;
        lazy[i][x] = 0;
    }
}

int query(int i, int a, int b, int x, int l, int r) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return 0;

    if(lazy[i][x] != 0 && l < r) {
        propagate(i, x, l, r);
    }

    if(l >= a && r <= b) {
        return dat[i][x];
    }

    int lquery = query(i, a, b, x*2+1, l, mid);
    int rquery = query(i, a, b, x*2+2, mid+1, r);
    return lquery + rquery;
}


void update(int i, int a, int b, int x, int l, int r, int val) {
    int mid = (l + r) / 2;
    if(r < a || l > b) return ;

    if(lazy[i][x] != 0 && l < r) propagate(i, x, l, r);

    if(l >= a && r <= b) {
        if(l != r) lazy[i][x] = val;
        if(val == 1) dat[i][x] = r - l + 1;
        else dat[i][x] = 0;
        return ;
    }

    update(i, a, b, (x << 1) + 1, l, mid, val);
    update(i, a, b, (x << 1) + 2, mid + 1, r, val);

    dat[i][x] = dat[i][(x<<1) + 1] + dat[i][(x<<1) + 2];
}



int query(int i, int a, int b){
    //cout << "querying i, a, b: " << i << " " << a << " " << b << endl;
    return query(i, a, b, 0, 0, n-1);}
void update(int i, int a, int b, int val){
    //cout << "updating i, a, b: " << i << " " << a << " " << b << endl;
    update(i, a, b, 0, 0, n-1, val);}

void print_out(){
    for(int i = 0; i < n; i++){
        int j;
        for(j = 0; j < 26; j++){
            if(query(j, i, i) > 0) break;
        }
        if(j == 26) printf("?");
        else printf("%c", 'a' + j);
    }
}




int main(){
    scanf("%d%d", &n, &q);
    getchar();
    getline(cin, s);
    for(int i = 0; i < n; i++){
        update(s[i]-'a', i, i, 0, 0, n-1, 1);
    }
    for(int i = 0; i < q; i++){
        scanf("%d%d%d", &a, &b, &k);
        a--, b--;
        int num[30];
        fill(num, num+30, 0);
        for(int j = 0; j < 26; j++){
            num[j] = query(j, a, b);
            if(num[j] > 0) update(j, a, b, -1);
        }
        if(k == 1){
            int las = a;
            for(int j = 0; j < 26; j++){
                if(num[j] > 0) update(j, las, las + num[j]-1, 1);
                las += num[j];
            }
        }
        else{
            int las = a;
            for(int j = 25; j >= 0; j--){
                if(num[j] > 0) update(j, las, las + num[j]-1, 1);
                las += num[j];
            }
        }
    }
    print_out();

}