#include <cstdio>
#include <string>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

struct node{
    int left, right;
	int key, Y;
	int size;
	ll sum;
	
//	node( int kkey, int YY ): key(kkey), Y(YY) { sum = kkey; }
};
// typedef node* pnode;
node all[1000030];
int kn;

int alloc( int kkey, int YY ) {
  all[kn].key = kkey;
  all[kn].Y = YY;
  all[kn].left = all[kn].right = -1;
  return kn++;
}

int getsize( int i )
{
    return i == -1 ? 0 : all[i].size;
}

ll getsum( int i ) 
{
  return i == -1 ? 0 : all[i].sum;
}

void update( int i )
{
    if ( i == -1 ) return;
	node& cur = all[i];
	cur.size = getsize( cur.left ) + getsize( cur.right ) + 1;
	cur.sum = getsum( cur.left ) + getsum( cur.right ) + cur.key;
}

void split( int i, int X, int& li, int& ri )
{
    if ( i == -1 ) { li=ri = -1; }
	else {
	    node& cur = all[i];
		if ( cur.key >= X ) split( cur.left, X, li, cur.left ), ri = i;
		else split( cur.right, X, cur.right, ri ), li = i;
	}
	update( li );
	update( ri );
}

void merge( int& i, int li, int ri )
{
    if ( li == -1 || ri == -1 )
       i = li == -1 ? ri : li;
	else
		if ( all[li].Y > all[ri].Y ) merge( all[li].right, all[li].right, ri ), i = li;
		else merge( all[ri].left, li, all[ri].left ), i = ri;
	update( i );
}

void insert( int& i, int nt )
{
    if ( i == -1 ) i = nt;
	else
		if ( all[i].Y < all[nt].Y ) split( i, all[nt].key, all[nt].left, all[nt].right ), i = nt;
		else insert( all[i].key > all[nt].key ? all[i].left : all[i].right, nt );
	update( i );
}

void erase( int& i, int X )
{
    if ( i == -1 ) return;
	if ( all[i].key == X ) {
	  merge( i, all[i].left, all[i].right );
	}
	else erase( all[i].key > X ? all[i].left : all[i].right, X );
	update( i );
}
/*
void printtree( pnode cur, int shift )
{
	if ( cur == NULL ) return;
	printtree( cur->left, shift+1 );
	printf( "%*s(%d:%d)\n", shift*2, " ", cur->key, cur->Y );
	printtree( cur->right, shift+1 );
}

void freemem( pnode cur ) 
{
  if ( cur == NULL ) return;

  freemem( cur->left );
  freemem( cur->right );
  delete cur;
}
*/
int R() 
{
  return ( ( rand() & 32767 ) << 15 ) + ( rand() & 32767 );
}

int n, x;
char s[123];
int rleft[5], rright[5], root[5];

int main()
{
	forn( i, 5 ) root[i] = -1;

	scanf( "%d", &n );
	forn( q, n ) 
	{
	  forn( i, 5 ) rleft[i] = rright[i] = -1;
	  scanf( "%s", s );
	  if ( s[0] == 'a' )
	  {
	    scanf( "%d", &x );
	    int ii = -1, mi = n+1;
	    forn( i, 5 ) 
	    {
	      split( root[i], x, rleft[i], rright[i] );
	      if ( getsize( rleft[i] ) < mi )
	      {
	        mi = getsize( rleft[i] );
	        ii = i;
	      }
	    }

	    forn( i, 5 )
	    {
	      int ti = i+1 == 5 ? 0 : i+1;
	      merge( root[ti], rleft[ti], rright[i] );
	    }

	    insert( root[ii], alloc( x, R() ) );
	  }

	  if ( s[0] == 'd' )
	  {
	    scanf( "%d", &x );
	    forn( i, 5 ) erase( root[i], x );

	    forn( i, 5 ) 
	      split( root[i], x, rleft[i], rright[i] );

	    forn( i, 5 )
	    {
	      int ti = i-1 == -1 ? 4 : i-1;
	      merge( root[ti], rleft[ti], rright[i] );
	    }
	  } 

	  if ( s[0] == 's' )
	  {
	    printf( "%I64d\n", getsum( root[2] ) );
	  }

/*	  printf( "---------------------------------------\n" );
	  printf( "After query %d, trees are:\n", q );
	  forn( i, 5 )
	  {
	    printf( "___ Tree %d: ___\n", i );
	    printtree( root[i], 0 );
	  } */
	}

//	forn( i, 5 ) freemem( root[i] );
}