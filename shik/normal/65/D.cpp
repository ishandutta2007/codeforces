// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define N 10010
using namespace std;
char s[N];
const char name[4][100]={"Gryffindor","Hufflepuff","Ravenclaw","Slytherin"};
int n,can[4];
set<vector<int> > vis;
int conv( char ch ) {
    for ( int i=0; i<4; i++ )
        if ( ch==name[i][0] ) return i;
    return -1;
}
void go( int p, vector<int> v ) {
    if ( vis.find(v)!=vis.end() ) return;
    vis.insert(v);
    int i,sml=*min_element(v.begin(),v.end());
    if ( p==n ) {
        for ( int i=0; i<4; i++ )
            if ( v[i]==sml ) can[i]=1;  
        return;
    }
    if ( s[p]!='?' ) {
        v[conv(s[p])]++;
        go(p+1,v);
        return;
    }
    for ( i=0; i<4; i++ ) {
        if ( v[i]!=sml ) continue;
        v[i]++;
        go(p+1,v);
        v[i]--; 
    }
}
int main()
{
    scanf("%d %s",&n,s);
    go(0,vector<int>(4,0));
    for ( int i=0; i<4; i++ )
        if ( can[i] ) puts(name[i]); 
    return 0;
}