#include <bits/stdc++.h>
using namespace std;
vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap_year(int y){
  if (y % 4 != 0){
    return false;
  } else if (y % 100 != 0){
    return true;
  } else if (y % 400 != 0){
    return false;
  } else {
    return true;
  }
}
void update(int &year, int &month, int &date, int &day){
  day++;
  if (day == 8){
    day = 1;
  }
  int nextdate = days[month - 1];
  if (month == 2 && is_leap_year(year)){
    nextdate++;
  }
  date++;
  if (date > nextdate){
    date = 1;
    month++;
  }
  if (month == 13){
    month = 1;
    year++;
  }
}
int main(){
  int s, m, h, day, date, month;
  cin >> s >> m >> h >> day >> date >> month;
  set<int> time_ok;
  for (int ss = 0; ss < 60; ss++){
    for (int mm = 0; mm < 60; mm++){
      for (int hh = 0; hh < 24; hh++){
        if ((h == -1 || h == hh) && (m == -1 || m == mm) && (s == -1 || s == ss)){
          time_ok.insert(hh * 3600 + mm * 60 + ss);
        }
      }
    }
  }
  vector<long long> year_sum(401, 0);
  for (int i = 0; i < 400; i++){
    year_sum[i + 1] = 86400;
    if (is_leap_year(i)){
      year_sum[i + 1] *= 366;
    } else {
      year_sum[i + 1] *= 365;
    }
    year_sum[i + 1] += year_sum[i];
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    long long t;
    cin >> t;
    long long t2 = t + 62167219200;
    t2 %= 12622780800;
    int yc = upper_bound(year_sum.begin(), year_sum.end(), t2) - year_sum.begin() - 1;
    t2 -= year_sum[yc];
    int dac = (t / 86400 + 3) % 7 + 1;
    int mc = 1;
    while (1){
      long long tmp = t2 - days[mc - 1] * 86400;
      if (mc == 2 && is_leap_year(yc)){
        tmp -= 86400;
      }
      if (tmp < 0){
        break;
      } else {
        t2 = tmp;
        mc++;
      }
    }
    int dtc = t2 / 86400 + 1;
    int time = t2 % 86400;
    if ((month == -1 || month == mc) && ((date != -1 && day != -1 && (date == dtc || day == dac)) || (date == dtc || date == -1) && (day == dac || day == -1))){
      auto itr = time_ok.upper_bound(time);
      if (itr != time_ok.end()){
        t += *itr - time;
        cout << t << endl;
        continue;
      }
    }
    t += 86400 - time;
    update(yc, mc, dtc, dac);
    while (1){
      if ((month == -1 || month == mc) && ((date != -1 && day != -1 && (date == dtc || day == dac)) || (date == dtc || date == -1) && (day == dac || day == -1))){
        t += *time_ok.begin();
        cout << t << endl;
        break;
      }
      update(yc, mc, dtc, dac);
      t += 86400;
    }
  }
}