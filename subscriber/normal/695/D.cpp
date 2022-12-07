#include <bits/stdc++.h>

using namespace std;

const int kd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int MAX = 24 * 60 * 60;
const int N = 1234567;

bool leap[N];
int nxt[N];

long long get_back(int day, int month, int year, int moment) {
  long long ans = 0;
  int yy = 1970;
  int mm = 1;
  while (yy < year) {
    int days = (leap[yy] ? 366 : 365);
    ans += days;
    yy++;
  }
  while (mm < month) {
    int rd = kd[mm] + ((mm == 2 && leap[yy]) ? 1 : 0);
    ans += rd;
    mm++;
  }
  ans += day - 1;
  ans = ans * MAX + moment;
  return ans;
}

int main() {
  for (int i = 0; i < N; i++) {
    leap[i] = false;
    if (i % 400 == 0) {
      leap[i] = true;
    }
    if (i % 100 != 0 && i % 4 == 0) {
      leap[i] = true;
    }
  }
  int s, m, h, day, date, month;
  cin >> s >> m >> h >> day >> date >> month;
  nxt[MAX] = MAX;
  for (int i = MAX - 1; i >= 0; i--) {
    int hh = i / 60 / 60;
    int mm = i / 60 % 60;
    int ss = i % 60;
    nxt[i] = nxt[i + 1];
    if (s != -1 && s != ss) {
      continue;
    }
    if (m != -1 && m != mm) {
      continue;
    }
    if (h != -1 && h != hh) {
      continue;
    }
    nxt[i] = i;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    long long ts;
    cin >> ts;
    ts++;
    int moment = ts % MAX;
    ts /= MAX;
    int yy = 1970;
    int dd = 1, mm = 1;
    int weekday = 4;
    while (true) {
      int days = (leap[yy] ? 366 : 365);
      if (ts >= days) {
        ts -= days;
        weekday += (leap[yy] ? 2 : 1);
        if (weekday > 7) {
          weekday -= 7;
        }
        yy++;
        continue;
      }
      while (true) {
        int rd = kd[mm] + ((mm == 2 && leap[yy]) ? 1 : 0);
        if (ts >= rd) {
          ts -= rd;
          weekday += rd % 7;
          if (weekday > 7) {
            weekday -= 7;
          }
          mm++;
          continue;
        }
        weekday += ts % 7;
        if (weekday > 7) {
          weekday -= 7;
        }
        dd = 1 + ts;
        break;
      }
      break;
    }
    while (true) {
      bool ok = true;
      if (month != -1 && month != mm) {
        ok = false;
      } else {
        if (day != -1 && date != -1) {
          if (day != weekday && date != dd) {
            ok = false;
          }
        } else {
          if (day != -1 && day != weekday) {
            ok = false;
          }
          if (date != -1 && date != dd) {
            ok = false;
          }
        }
      }
      if (ok) {
        if (nxt[moment] < MAX) {
          moment = nxt[moment];
          break;
        }
      }
      weekday++;
      if (weekday > 7) {
        weekday -= 7;
      }
      int rd = kd[mm] + ((mm == 2 && leap[yy]) ? 1 : 0);
      if (dd == rd) {
        dd = 1;
        mm++;
        if (mm > 12) {
          mm = 1;
          yy++;
        }
      } else {
        dd++;
      }
      moment = 0;
    }
    long long res = get_back(dd, mm, yy, moment);
    cout << res << endl;
  }
  return 0;
}