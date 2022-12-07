#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
#define mod7 1000000007LL
#define eps 1e-9
inline LL getint(){
  LL _x=0,_tmp=1; char _tc=getchar();
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline LL add( LL _x , LL _y , LL _mod = mod7 ){
  _x += _y;
  return _x >= _mod ? _x - _mod : _x;
}
inline LL sub( LL _x , LL _y , LL _mod = mod7 ){
  _x -= _y;
  return _x < 0 ? _x + _mod : _x;
}
inline LL mul( LL _x , LL _y , LL _mod = mod7 ){
  _x *= _y;
  return _x >= _mod ? _x % _mod : _x;
}
LL mypow( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 1LL;
  LL _ret = mypow( mul( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = mul( _ret , _a , _mod );
  return _ret;
}
LL mymul( LL _a , LL _x , LL _mod ){
  if( _x == 0 ) return 0LL;
  LL _ret = mymul( add( _a , _a , _mod ) , _x >> 1 , _mod );
  if( _x & 1 ) _ret = add( _ret , _a , _mod );
  return _ret;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
void sleep( double sec = 1021 ){
  clock_t s = clock();
  while( clock() - s < CLOCKS_PER_SEC * sec );
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/
#define N 101010
int ss[1010][1010];
void build(){

}
bool isp( LL x ){
  if( x == 1 ) return false;
  for( LL i = 2 ; i * i <= x ; i ++ )
    if( x % i == 0 )
      return false;
  return true;
}
LL n , m , goal;
void init(){
  n = getint();
  m = getint();
}
void solve(){
  goal = n - 1;
  while( not isp( goal ) )
    goal ++;
  printf( "%lld %lld\n" , goal , goal );
  for( int i = 1 ; i < n ; i ++ )
    printf( "%d %d %lld\n" , i , i + 1 , (i + 1 == n ? goal - (n - 2): 1) );
  m -= n - 1;
  for( int i = 1 ; i <= n and m > 0 ; i ++ )
    for( int j = i + 2 ; j <= n and m > 0 ; j ++ ){
      printf( "%d %d %lld\n" , i , j , goal + goal );
      m --;
    }
}
int main(){
  build();
  for(int i=0; i<1010; i++)
  {
      for(int j=0; j<1010; j++)
      {
          ss[i][j] = -1;
      }
  }
  //__ = getint();
  while( __ -- ){
    init();
    solve();
  }
}