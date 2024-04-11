#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <deque>

#define fab(i, a, b) for(int i = a; i <= b; i++)
#define fdown(i, n) for(int i = n - 1; i >= 0; i--)
#define fr(i, n) for(int i = 0; i < n; i++)
#define mp make_pair
#define pb push_back
#define pint pair <int, int>
#define vint vector <int>
#define vpint vector < pair <int, int> >
#define ff first
#define ss second
#define cpr(n) cout.precision(n);

typedef long long ll;
typedef long double ld;
typedef double db;

const ll inf = 1e9;
const ld eps = 1e-6;
const ll N = 1e6;
const ll M = 1e6;

using namespace std;

void ret(string s)
{
  cout << s;
  exit(0);
}

int get_random(int &x, int a, int b, int c){
  x = (x * a + b) % c;
  return x;
}

string s;
int n, k, kol, sc, aa, bb, cc, x, num, h;
pair <int, string> a[N];
pair <int, string> b[4][N];
bool u[4][N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> x >> aa >> bb >> cc;
    fr(i, n){

      cin >> s >> sc;
      a[i] = mp(-sc, s);

    }

    sort(a, a + n);
    fr(i, n){
      b[i / (n / 4)][i % (n / 4)] = a[i];
    }

    fr(i, n / 4){
      //cerr << "ok\n";
      printf("Group %c:\n", 'A' + i);
      fr(j, 4){
        x = get_random(x, aa, bb, cc);
        //cerr << x << "\n";
        h = x % (n / 4 - i);
        num = 0;
        fr(ii, n / 4){
          if (u[j][ii] == false) num++;
          if (num == h + 1){
            cout << b[j][ii].ss << "\n";
            u[j][ii] = true;
            break;
          }
        }
      }
    //cerr << "fok\n";
    }

    return 0;
}