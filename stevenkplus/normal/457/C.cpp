#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > minheap;
typedef priority_queue<int> maxheap;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXN = 100100;

int N;
vector<int> ar[MAXN];


int loc[MAXN];
int cnt[MAXN];

int osum = 0;
maxheap cur;
minheap pot;

void put(int x) {
  pot.push(x);
}

void setsize(int size) {
  while (cur.size() > size) {
    osum -= cur.top();
    pot.push(cur.top());
    cur.pop();
  }
  while (cur.size() < size) {
    osum += pot.top();
    cur.push(pot.top());
    pot.pop();
  }
  while (!cur.empty() && !pot.empty() && cur.top() > pot.top()) {
    osum -= cur.top();
    pot.push(cur.top());
    cur.pop();
    osum += pot.top();
    cur.push(pot.top());
    pot.pop();
  }
}



int main() {
  scanf("%d", &N);
  int sum = 0;
  int votes = 0;
  for(int i = 0; i < N; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ar[a].push_back(b);
    ++cnt[a];

    sum += b; // initially, buy all votes.
    ++votes;
  }

  vector<int> guys;
  for(int i = 1; i < MAXN; ++i) {
    if (cnt[i]) {
      guys.push_back(i);
      sort(ar[i].begin(), ar[i].end());
      reverse(ar[i].begin(), ar[i].end());
    }
  }

  int best = sum;
  for(int i = 0; i + 1 < N; ++i) {
    vector<int> _guys;
    repi(j, guys) {
      int g = *j;
      if (cnt[g] > i) {
        --votes;
        sum -= ar[g][i]; // he can have a vote.

        put(ar[g][i]); // but we might want to buy it back.
        _guys.push_back(g);
      }
    }

    int need = i + 2 - votes;
    if (need < 0) need = 0;
    setsize(need);
    int val = sum + osum; // votes we must buy + votes from plebes
    if (val < best) best = val;

    guys = _guys;
  }
  printf("%d\n", best);
}