#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;

Int gcd(Int x, Int y, Int &a, Int &b){
  if(x == 0){
    a = 0;
    b = 1;
    return y;
  }
  Int res = gcd(y%x, x, b, a);
  a -= b * (y / x);
  return res;
}

Int n;

void output(Int a, Int b){
  Int aa, bb;
  Int g = gcd(a, b, aa, bb);
  cout << a/g << " " << b/g << endl;
}

int main(){
  cin >> n;
  Int nn = n;
  set<Int> hoge;
  for(int i = 2;i * i <= n;i++){
    while(n % i == 0){
      hoge.insert(i);
      n /= i;
    }
  }
  if(n != 1)hoge.insert(n);
  if(hoge.size() == 1){
    cout << "NO" << endl;
    return 0;
  }
  set<Int>::iterator it = hoge.begin();
  Int x = 1;
  Int y = nn;
  while(y % *it == 0){
    x *= *it;
    y /= *it;
  }
  Int a, b;
  gcd(x, y, a, b);
  a *= -1;
  b *= -1;

  //cout << x * a + y * b << " " << x << "*" << a << " " <<y<<"*"<<b<<endl;
  if(a > 0){
    b += x * (a/y);
    a %= y;
  }
  if(b > 0){
    a += y * (b/x);
    b %= x;
  }
  //cout << x * a + b * y << " " << x << "*" << a << " " <<y<<"*"<<b<<endl;
  if(a < 0)a += y;
  if(b < 0)b += x;
  //cout << x * a + b * y << " " << x << "*" << a << " " <<y<<"*"<<b<<endl;
  cout << "YES" << endl;
  cout << 2 << endl;
  output(x*a,nn);
  output(b*y,nn);
  return 0;
}