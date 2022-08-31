#include <bits/stdc++.h>
using namespace std;
constexpr int P = 2154; //100000^(2/3)
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  vector<int> a_val(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    b[i] = a[i];
    a_val[i] = a[i];
  }
  //t/P, l/P, r, l, t, i
  vector<tuple<int, int, int, int, int, int>> mex;
  //index, old value, new value
  vector<tuple<int, int, int>> update;
  int upd_cnt = 0;
  for (int i = 0; i < q; i++){
    int T;
    cin >> T;
    if (T == 1){
      int l, r;
      cin >> l >> r;
      l--;
      mex.emplace_back(upd_cnt / P, l / P, r, upd_cnt, l, mex.size());
    }
    if (T == 2){
      int p, x;
      cin >> p >> x;
      p--;
      update.emplace_back(p, b[p], x);
      b[p] = x;
      a_val.emplace_back(x);
      upd_cnt++;
    }
  }
  int mex_cnt = mex.size();
  //compress
  sort(a_val.begin(), a_val.end());
  a_val.erase(unique(a_val.begin(), a_val.end()), a_val.end());
  int a_cnt = a_val.size();
  unordered_map<int, int> mp;
  for (int i = 0; i < a_cnt; i++){
    mp[a_val[i]] = i;
  }
  for (int i = 0; i < n; i++){
    a[i] = mp[a[i]];
  }
  for (int i = 0; i < upd_cnt; i++){
    get<1>(update[i]) = mp[get<1>(update[i])];
    get<2>(update[i]) = mp[get<2>(update[i])];
  }
  //sort mex queries
  sort(mex.begin(), mex.end());
  //current
  vector<int> freq(a_cnt, 0);
  vector<int> freq_cnt(n + 1, 0);
  freq_cnt[0] = a_cnt;
  vector<int> ca = a;
  int ct = 0;
  int cl = 0;
  int cr = 0;
  //answer of queries
  vector<int> ans(mex_cnt, -1);
  for (int i = 0; i < mex_cnt; i++){
    int r, t, l, c;
    tie(ignore, ignore, r, t, l, c) = mex[i];
    //update ct
    //undo (ct-1)-th to t-th update query
    while (ct > t){
      ct--;
      int update_pos, old_value, new_value;
      tie(update_pos, old_value, new_value) = update[ct];
      if (cl <= update_pos && update_pos < cr){
        //update frequency table
        freq_cnt[freq[new_value]]--;
        freq[new_value]--;
        freq_cnt[freq[new_value]]++;
        freq_cnt[freq[old_value]]--;
        freq[old_value]++;
        freq_cnt[freq[old_value]]++;
      }
      ca[update_pos] = old_value;
    }
    //apply ct-th to (t-1)-th update query
    while (ct < t){
      int update_pos, old_value, new_value;
      tie(update_pos, old_value, new_value) = update[ct];
      if (cl <= update_pos && update_pos < cr){
        //update frequency table
        freq_cnt[freq[old_value]]--;
        freq[old_value]--;
        freq_cnt[freq[old_value]]++;
        freq_cnt[freq[new_value]]--;
        freq[new_value]++;
        freq_cnt[freq[new_value]]++;
      }
      ca[update_pos] = new_value;
      ct++;
    }
    //move cl, cr
    //insert (cl-1)-th to l-th element
    while (l < cl){
      cl--;
      freq_cnt[freq[ca[cl]]]--;
      freq[ca[cl]]++;
      freq_cnt[freq[ca[cl]]]++;
    }
    //insert cr-th to (r-1)-th element
    while (cr < r){
      freq_cnt[freq[ca[cr]]]--;
      freq[ca[cr]]++;
      freq_cnt[freq[ca[cr]]]++;
      cr++;
    }
    //erase cl-th to (l-1)-th element
    while (cl < l){
      freq_cnt[freq[ca[cl]]]--;
      freq[ca[cl]]--;
      freq_cnt[freq[ca[cl]]]++;
      cl++;
    }
    //erase (cr-1)-th to r-th element
    while (r < cr){
      cr--;
      freq_cnt[freq[ca[cr]]]--;
      freq[ca[cr]]--;
      freq_cnt[freq[ca[cr]]]++;
    }
    //debug
    /*
    cout << "ct = " << ct << ", cl = " << cl << ", cr = " << cr << endl;
    cout << "freq: ";
    for (int j = 0; j < a_cnt; j++){
      cout << a_val[j] << ": " << freq[j] << ", ";
    }
    cout << endl;
    */
    //find ans
    int q_ans = 1;
    while (freq_cnt[q_ans]){
      q_ans++;
    }
    ans[c] = q_ans;
  }
  for (int i = 0; i < mex_cnt; i++){
    cout << ans[i] << "\n";
  }
}