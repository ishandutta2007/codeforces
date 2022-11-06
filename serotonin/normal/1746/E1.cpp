#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

bool ask(set <int> st) {
   printf("? %d", st.size());
   for(int x : st) printf(" %d", x);
   cout << endl;

   string s; cin >> s;
   return s == "YES";
}

void quer(int x) {
   printf("! %d\n", x); fflush(stdout);

   string s; cin >> s;
   if(s == ":)") exit(0);
}

void idk(set <int> &rhs) {
   set <int> now;
   for(int x : rhs) {
      if(now.size() * 2 >= rhs.size()) break;
      now.insert(x);
   }
   bool q = ask(now);
   if(q) rhs = now;
   else for(int x : now) rhs.erase(x);
}

set <int> solve(set <int> a) {
   int n = a.size();

   if(n <= 3) return a;

   set <int> lhs;
   int j = 0;
   for(int x : a) {
      j++;
      if(j * 2 > n) break;
      lhs.insert(x);
   }

   set <int> rhs = a;
   for(int x : lhs) rhs.erase(x);

   if(ask(lhs)) idk(rhs);
   else idk(lhs);

   a.clear();
   for(int x : lhs) a.insert(x);
   for(int x : rhs) a.insert(x);
   return solve(a);
}

int main() {
   int n;
   cin >> n;

   set <int> a;
   for(int i=1; i<=n; i++) a.insert(i);
   auto res = solve(a);

   if(res.size() == 1) {
      quer(*res.begin());
   }
   else if(res.size() == 2) {
      quer(*res.begin());
      res.erase(res.begin());
      quer(*res.begin());
   }
   else {
      for(int x : res) {
         a.clear();
         a.insert(x);
         bool f = ask(a);
         if(f) {
            quer(x);
            res.erase(x);
            a.clear();
            a.insert(*res.begin()); 
            if(ask(a)) quer(*res.begin());
            else res.erase(res.begin()), quer(*res.begin());
         }
         f = ask(a);
         if(f) {
            quer(x);
            res.erase(x);
            a.clear();
            a.insert(*res.begin()); 
            if(ask(a)) quer(*res.begin());
            else res.erase(res.begin()), quer(*res.begin());
         }
      }
   }
}