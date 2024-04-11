// Bismillahirrahmanir Rahim
//NAMOMIZARAHID
#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>

#define nl printf("\n")
#define sp printf(" ")

#define rep(i,a,b) for(i=a;i<=b;i++)
#define rev(i,a,b) for(i=a;i>=b;i--)

#define fil freopen("input.txt","r",stdin)

#define pf printf
#define sf scanf


typedef long long l;
typedef unsigned long long ul;

using namespace std;

#define pi acos(-1.0)
#define mp make_pair
#define pb push_back
#define p_q priority_queue


#define dis( a ,b ) abs( a - b )
#define dis2d( x1 ,y1 ,x2 ,y2 )    sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) )
#define dis3d( x1 ,y1 ,z1 ,x2 ,y2 ,z2 )    sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) + ( z1 - z2 ) * ( z1 - z2 ) )


#define C(i) pf("Case %lld: ",i)
#define Ci(i) pf("Case %d: ",i)


typedef pair< l ,l > pll;
typedef pair< string ,l > psl;
typedef pair< l ,string > pls;
typedef pair< string ,string > pss;
typedef pair< char ,l > pcl;
typedef pair< l ,char > plc;


#define Inf 0x7f7f7f
#define Max 200000001
#define Min -100000000001
#define mod 1000000007

#define ms0(a) memset(a,0,sizeof(a))
#define ms1(a) memset(a,1,sizeof(a))
#define ms_1(a) memset(a,-1,sizeof(a))


#define DBG pf("I am here\n")

#define valid(nx,ny,r,c) nx>=0&&nx<=r-1 && ny>=0&&ny<=c-1

#define ck_bt( v , p ) ( ( v >> p ) & 1 )

char tochar( int x )
{
    return x + '0' ;
}

int toint( char x )
{
    return x - '0' ;
}


int inline in(){int x;sf("%d",&x);return x;}
l inline lin(){l x;sf("%lld",&x);return x;}
void P(l x){pf("%lld",x);}
void Pi(int x){pf("%d",x);}


l fx[]={0,0,-1,1,-1,-1,1,1};
l fy[]={-1,1,0,0,-1,1,-1,1};



/*
    rep( i , 1 , n )
    {
        a[i] = lin() ;
    }

*/


/** Big mod **/




bool prm[1000007];
l N= 1000000;

void sieve()
{
    prm[1]=1;
    for(l i=2;i<=sqrt(N);i++)
    {
        if(prm[i]==0)
        {
            for(l j=i+i;j<=N;j=j+i)prm[j]=1;
        }
    }
}

l gcd(l a,l b)
{
     if(b == 0)
     {
         return a;
     }
     else
       return gcd(b, a % b);
}


/** Longest common multiplexer **/


l lcm(l a,l b)
{
    return (a*b)/gcd(a,b);
}

l fac( l d )
{
    l x = 1 , i ;
    rep( i , 2 , d )
    {
        x *= i ;
    }
    return x ;
}
/*
struct info
{
    l x,y,z;
    info() {};
    info(l _x, l _y,l _z) {x = _x; y = _y; z = _z;};

    bool operator < (const info &p) const
    {
		if(y == p.y) return x < p.x;
		else
			return y < p.y;
    }
}a[100010] , b[100010];
*/



#define rng 100010


l  n ;

l a[500010] , b[500010] ;

char s1[3000010] , s2[3000010], r[3000010] ;

multiset<char> S1 , S2 ;

map<char,l>na1 , na2 ;

multiset<char>::iterator it ;
multiset<char>::reverse_iterator rit ;

int main()
{

    l i , j ;

    //fil;
    //freopen("out.txt","w",stdout);
    //pf("%d",'1'-48) ;
    //sf("%s",&s) ;
    //n = strlen( s ) ;

    sf("%s",&s1) ;
    sf("%s",&s2) ;
    n = strlen( s1 ) ;

    rev( i , n , 1 )
    {
        s1[i] = s1[i-1] ;
        s2[i] = s2[i-1] ;
    }

    sort( s1 + 1 , s1 + n + 1 ) ;
    sort( s2 + 1 , s2 + n + 1 ) ;




    //P( na2['x'] ) ; nl ;

    l left = 1 , right = n ;

    l f1left = 1 , f1right = n , f2left = 1 , f2right = n ;

    char c1 , c2 , cc ;

    bool ck = 0 ;

    rep( i , 1 , n )
    {
        c1 = s1[f1left] ;
        c2 = s2[f2right] ;
        if( ck == 0 ){
            if( c1 < c2 )
            {
                if( i % 2 )
                {
                    r[left] = c1 ;
                    f1left ++ ;
                    left ++ ;
                }
                else
                {
                    r[left] = c2 ;
                    f2right -- ;
                    left ++ ;
                }
            }
            else
            {
                ck = 1 ;
                if( i % 2 )
                {
                    l baki = 1 + ( n - i ) / 2 ;

                    l pos = f1left + baki - 1 ;

                    f1right = pos ;

                    baki = ( n - i ) / 2 + bool ( ( n - i ) % 2 ) ;
                    pos = f2right - baki + 1 ;
                    f2left = pos ;

                    r[right] = s1[f1right] ;
                    f1right -- ;
                    right -- ;
                }
                else
                {

                    l baki = 1 + ( n - i ) / 2 ;
                    l pos = f2right - baki + 1 ;

                    f2left = pos ;


                    baki = ( n - i ) / 2 + bool ( ( n - i ) % 2 ) ;
                    pos = f1left + baki - 1 ;
                    f1right = pos ;

                    r[right] = s2[f2left] ;
                    f2left ++ ;
                    right -- ;

                }
            }
        }
        else
        {
            if( i % 2 )
            {
                r[right] = s1[f1right] ;
                f1right -- ;
                right -- ;
            }
            else
            {
                r[right] = s2[f2left] ;
                f2left ++ ;
                right -- ;
            }
        }
    }

    rep( i , 1 , n )
    {
        pf("%c",r[i]) ;
    }

    return 0;
}