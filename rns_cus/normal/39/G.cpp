#include<bits/stdc++.h>
using namespace std;
#define mod 32768
char temp;
string s[110], tp;
int cnt, f[32780], tot, pos, n, ans, answer;

int calc();

int getnum(){
   int rlt = 0;
   if(tp[pos] == 'n') return pos ++, n;
   if(tp[pos] == 'f') return pos +=2, rlt = f[calc()], pos++, rlt;
   while(tp[pos] > 47 and tp[pos] < 58) rlt = rlt * 10 + tp[pos] - 48, pos ++;
   return rlt;
}

int mul(){
   int rlt = getnum(), tt;
   while(tp[pos] == '*' or tp[pos] == '/'){
      char c = tp[pos]; pos ++;
      tt = getnum();
      if(c == '*') rlt = 1ll * rlt * tt % mod;
      else rlt = (rlt / tt) % mod;
   }
   return rlt;
}

int calc(){
   int rlt = mul(), tt;
   while(tp[pos] == '+' or tp[pos] == '-'){
      char c = tp[pos]; pos ++;
      tt = mul();
      if(c == '+') rlt = (rlt + tt) % mod;
      else rlt = (rlt + mod - tt) % mod;
   }
   return rlt;
}

bool cnd(){
   int x1, x2, opp;
   x1 = calc();
   if(tp[pos] == '='){ opp = 1; pos += 2;}
   else if(tp[pos] == '<'){ opp = 2; pos ++; }
   else{opp = 3; pos ++; }
   x2 = calc();
   if(opp == 1) return x1 == x2;
   if(opp == 2) return x1 < x2;
   if(opp == 3) return x1 > x2;
   return 0;
}

int get_ans(){
   for(int i = 0; i < cnt; i ++){
      tp = s[i];
      if(tp[0] == 'i'){  pos = 3;
         if(cnd()) return pos += 7, calc();
      }
      else return pos = 6, calc();
   }
   return -1;
}

int main(){
   cin >> ans >> temp;
   while(temp != '{'){ cin >> temp; }
   cnt = 0, tot = -1;
   while(1){
      cin >> temp;
      if(temp == '}') break;
      if(temp == ';') cnt ++;
      else s[cnt] += temp;
   }
   answer = -1;
   for(int i = 0; i < mod; i ++){
      n = i; f[i] = get_ans();
      if(f[i] == ans) answer = i;
   }
   cout << answer << endl;
}