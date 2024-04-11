#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

class StringTokenizer {
public:
  char st[110];
  int nst, ip;

  StringTokenizer() { st[0] = '\0'; nst=ip=0; }
  StringTokenizer( string& s ) { eat( s.c_str() ); }
  StringTokenizer( char* s ) { eat( s ); }

  void eat( const char* s )
  {
    strcpy( st, s );
    nst = strlen( st );
    ip = 0;
  } 

  bool hasMoreTokens()
  {
    while ( ip < nst && st[ip] == ' ' ) ip++;
    return ip < nst;
  }

  string nextToken()
  {
    while ( ip < nst && st[ip] == ' ' ) ip++;
    string res = "";
    res += st[ip++];
    if ( res == "+" || res == "-" || res == "*" || res == "/" || res == "#" || res == "(" || res == ")" ) return res;
    while ( ip < nst && st[ip] != ' ' && st[ip] != '+' && st[ip] != '-' && st[ip] != '*' &&
            st[ip] != '/' && st[ip] != '(' && st[ip] != ')' ) res += st[ip++];

    return res;
  }

};

int n, kid;
char s[110];
map<string,int> mm;
string value[110];
bool fa[110], fm[110], u[110], ok[110];
int fl[110];

void addMap( string s, string t )
{
  mm[s] = kid;
  value[kid] = t;
  kid++;
}

bool checkToken( string& st, bool& fla, bool& flm, int& lasta )
{
//  cout << "check " << st << endl;
  if ( mm.find(st) == mm.end() )
  {
    fla = flm = false;
	lasta = 0;
    return true;
  }

  int id = mm[st];

  if ( u[id] ) 
  {
    fla = fa[id];
    flm = fm[id];
    lasta = fl[id];
    return ok[id];
  }

  u[id] = true;
  ok[id] = false;
  StringTokenizer ST( value[id] );

  char St[110];
  int tos = 0; 
  int kbr = 0;

  fla = flm = false;
  lasta = 0;
  bool qfla = false, qflm = false;
  int ql = 0;
  while ( ST.hasMoreTokens() )
  {
    string st = ST.nextToken();
    if ( st == "+" || st == "-" || st == "/" || st == "*" || st == "(" )
    {
      St[ ++tos ] = st[0];
      if ( st == "+" || st == "-" ) 
      {
        fla |= kbr == 0;
        if ( kbr == 0 ) lasta = 1;
      }

      if ( st == "*" || st == "/" ) 
      {
        if ( qfla ) return false;
        flm |= kbr == 0;
        if ( kbr == 0 ) lasta = 2;
      }
      if ( st == "(" ) kbr++;
    }
    else
      if ( st == ")" )
      {
        while ( St[tos] != '(' ) tos--;
        tos--;
        if ( tos > 0 && St[tos] != '(' ) tos--;
        kbr--;
		qfla = false;
      }
      else
      {
        if ( !checkToken( st, qfla, qflm, ql ) )
          return false;

        fla |= qfla && kbr == 0;
        flm |= qflm && kbr == 0; 
        if ( ql != 0 )
          lasta = ql;
       
        if ( tos == 0 || St[tos] == '(' ) continue;
        if ( St[tos] == '+' )
        {
          tos--;
          continue;
        }

        if ( St[tos] == '-' || St[tos] == '*' )
        {
          if ( qfla ) return false;
          tos--;
          continue;
        }

        if ( St[tos] == '/' )
        {
          if ( qfla || qflm ) return false;
          tos--;
          continue;
        }
      }
  }

  fa[id] = fla;
  fm[id] = flm;
  fl[id] = lasta;
  return ok[id] = true;
}

int main()
{
//	freopen( "input.txt", "r", stdin );
  scanf( "%d", &n ); gets( s );
  for ( int i=0; i<n; i++ )
  {
    gets( s );
    StringTokenizer ST( s );

    ST.nextToken();
    ST.nextToken();
    string name = ST.nextToken();
    string val = ST.nextToken();
    while ( ST.hasMoreTokens() )
      val += ST.nextToken();

    addMap( name, val );                 
  }

  bool f1, f2;
  int f3;
  gets( s );
  string sin( s );
  string name = "RomkaLovesAnnie";
  addMap( name, sin );
  if ( checkToken( name, f1, f2, f3 ) ) printf( "OK\n" );
  else printf( "Suspicious\n" );
}