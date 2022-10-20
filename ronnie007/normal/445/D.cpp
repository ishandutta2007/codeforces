#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

long long n , d , x ;
int a[ 100007 ] ;
int b[ 100007 ] ;
int pl[ 100007 ] ;
int c[ 100007 ] ;
int o[ 100007 ] ;

void input ( ) ;
void solve ( ) ;


long long getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    int i ;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main ( ) {
    //freopen ( "input.txt" , "r" , stdin ) ;
    //freopen ( "output.txt" , "w" , stdout ) ;
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}


void input ( ) {
    cin >> n >> d >> x ;
    initAB ( ) ;
}


void solve ( )  {
        vector<int> pos;
        for (int i = 0; i < n; i++) if (b[i]) pos.push_back(i);
        for (int i = 0; i < n; i++) c[i] = 0;
        for (int i = 0; i < n; i++) o[a[i]] = i;

        int cnt = n, cur = n;
        while (cnt > 500 && cur >= 0) {
            for (int i = 0; i < (int)pos.size(); i++) {
                if (o[cur] + pos[i] < n && c[o[cur] + pos[i]] == 0) {
                    c[o[cur] + pos[i]] = cur;
                    cnt--;
                }
            }
            cur--;
        }
        for (int i = 0; i < n; i++) if (c[i] == 0) {
            for (int j = 0; j < (int)pos.size() && i - pos[j] >= 0; j++) {
                c[i] = max(c[i], a[i - pos[j]]);
            }
        }
        //cerr << n << " " << d << " " << x << endl;
        for (int i = 0; i < n; i++) printf("%d\n", c[i]);
}