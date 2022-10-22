#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int n , m , k;

char s[1005];

struct fun
{
  int sz;
  int a[5];
  bool operator == (const fun& r) const{
    if (sz != r.sz) return 0;
    for (int i = 0 ; i < sz ; ++ i)
        if (!(a[i] & r.a[i]))
           return 0;
    return 1;
  }
};
string name;
map<string , int > call;
map<string , vector<fun> > f;
map<string , int> v;
int main()
{
 //  freopen("~input.txt" , "r" , stdin);
   int i , j , k , l , x , y;
   scanf("%d\n",&n);
   call["T"] = 7 , call["double"] = 1 , call["int"] = 2 , call["string"] = 4;
   for (j = 0 ; j < n ; ++ j)
   {
     gets(s);
     for (i = 0 , k = 0; s[i] ; ++ i)
        if (s[i] != ' ')
          s[k ++] = s[i];
     s[k] = 0;
     string temp; fun F = {}; name = "";
     for (i = 4 ; s[i] != '(' ; ++ i)
        name = name + s[i];
     for (i = i + 1 ; s[i] ; ++ i)
     {
       if (s[i] == ',' || s[i] == ')')
         F.a[F.sz ++] = call[temp] , temp = "";
       else temp = temp + s[i];
     }
     f[name].push_back(F);
   }
   scanf("%d\n",&m);
   for (j = 0 ; j < m ; ++ j)
   {
     gets(s);
     for (i = 0 , k = 0; s[i] ; ++ i)
        if (s[i] != ' ')
          s[k ++] = s[i];
     s[k] = 0 ,  name = "";
     if (s[0] == 'i')
     {
       for (i = 3 ; s[i] ; ++ i)
         name = name + s[i];
       v[name] = 2;
     }
     if (s[0] == 'd')
     {
       for (i = 6 ; s[i] ; ++ i)
         name = name + s[i];
       v[name] = 1;
     }
     if (s[0] == 's')
     {
       for (i = 6 ; s[i] ; ++ i)
         name = name + s[i];
       v[name] = 4;
     }
     //cout << name << v[name] << endl;
   }
   scanf("%d\n",&m);
   while (m --)
   {
     x = 0 , gets(s);
     for (i = 0 , k = 0; s[i] ; ++ i)
        if (s[i] != ' ')
          s[k ++] = s[i];
     s[k] = 0;
     string temp; fun F = {}; name = "";
     for (i = 0 ; s[i] != '(' ; ++ i)
        name = name + s[i];
     for (i = i + 1 ; s[i] ; ++ i)
     {
       if (s[i] == ',' || s[i] == ')')
         F.a[F.sz ++] = v[temp] , temp = "";
       else temp = temp + s[i];
     }
     for (i = 0 ; i < f[name].size() ; ++ i)
        if (f[name][i] == F)
           ++ x;
     cout << x << endl;
   }
   return 0;
}