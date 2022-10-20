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

const int maxn = 200020;
char s[maxn] , t[maxn];
int have[maxn][28] ;
int le[maxn] , ri[maxn];

void read (){
    scanf ( "%s" , s);
    scanf ( "%s" , t);
}

void solve (){
    int i , j ;
    int n = strlen(s);
    int m = strlen(t);
    for ( i = 1; i <= m; ++i ) {
        for ( j = 0; j < 26; ++j )  have[i][j] = have[i-1][j];
        have[i][t[i-1]-'a']++;
    }
    int pos = 0;
    for ( i = 0; i < n; ++i ) {
        if ( pos < m &&s[i] == t[pos] ) {
            le[i] = pos+1;
            pos++;
        } else le[i] = pos+1;
    }
    pos = m -1;
    for ( i = n-1; i >= 0; --i ) {
        if ( pos > -1 && s[i] == t[pos] ) {
            ri[i] = pos+1;
            pos--;
        } else ri[i] = pos+1;
    }
    for ( i = 0; i < n; ++i ) {
        int c = s[i]-'a';
        int ml = le[i];
        int mr = ri[i];
        if ( ml == m+1)ml = m;
        if ( mr == 0 ) mr = 1;

        if ( mr > ml || have[ml][c]-have[mr-1][c] < 1) {
            cout << "No\n" ;
            return;
        }
    }
    cout << "Yes\n";
}

int main () {
     read ();
     solve ();
     return 0;
}