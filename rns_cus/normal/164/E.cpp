#include <bits/stdc++.h>
using namespace std;
#define inf 1010001000
#define N 401000
int t[N], addt[N], di[N], addi[N];
typedef pair<int, int> pi;
set<pi> S;
set<pi> :: iterator it;
void push_up(int id) {
    int l = id * 2;
    int r = id * 2 + 1;
    t[id] = max(t[l], t[r]);
    di[id] = min(di[l], di[r]);
    return ;
}

void push_down(int id) {
    int l = id * 2;
    int r = id * 2 + 1;
    if(addt[id]) {
        addt[r] += addt[id];
        addt[l] += addt[id];
        t[r] += addt[id];
        t[l] += addt[id];
        addt[id] = 0;
    }
    if(addi[id]) {
        addi[r] += addi[id];
        addi[l] += addi[id];
        di[l] += addi[id];
        di[r] += addi[id];
        addi[id] = 0;
    }
}

void build(int st, int en, int id) {
    t[id] = 0;
    di[id] = inf;
    if(st == en) {
        return ;
    }
    int mid = (st + en) >> 1;
    build(st, mid, id * 2);
    build(mid + 1, en, id * 2 + 1);
}

void cha(int l, int r, int st, int en, int id, int tt, int va) {
    if(l > en || r < st) return ;
    if(l <= st && en <= r) {
        addt[id] += tt;
        t[id] += tt;
        di[id] += va;
        addi[id] += va;
        return ;
    }
    push_down(id);
    int mid = (st + en) >> 1;
    cha(l, r, st, mid, id * 2, tt, va);
    cha(l, r, mid + 1, en, id * 2 + 1, tt, va);
    push_up(id);
}

int calcid(int st, int en, int id, int va) {
    if(st == en) {
        return st;
    }
    push_down(id);
    int mid = (st + en) >> 1;
    if(di[id * 2 + 1] < va) return calcid(mid + 1, en, id * 2 + 1, va);
    return calcid(st, mid, id * 2, va);
}

int Mx(int l, int r, int st, int en, int id) {
    if(l > en || st > r) return 0;
    if(l <= st && en <= r) return t[id];
    push_down(id);
    int mid = (st + en) >> 1;
    return max(Mx(l, r, st, mid, id * 2), Mx(l, r, mid + 1, en, id * 2 + 1));
}

int ti[N];
int main() {
    int l, r;
    //freopen("1.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int ans = 0;
    build(1, n, 1);
    int xx = 0;
    int Id = 0;
    S.clear();
    for(int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &l, &r, &ti[i]);
        r ++;
        int stt = max(ans, l);
        if(stt + ti[i] <= r) {
            printf("0 ");
            pi ab = pi(ti[i], i);
            S.insert(ab);
            xx = ti[i];
            Id = i;
            cha(i, i, 1, n, 1, ti[i], -inf + stt - l);
            ans = stt + ti[i];
            continue;
        }
        int st = xx;
        int en = inf;
        while(en - st > 1) {
            int mid = (en + st) >> 1;
            int id = calcid(1, n, 1, mid);
            int xxx = Mx(id, n, 1, n, 1);
            if(xxx >= mid) st = mid;
            else en = mid;
        }
        int id = calcid(1, n, 1, st);
        int st1 = max(l, ans - st);
        if(st1 + ti[i] > r || ans <= st1 + ti[i]) {
            printf("-1 ");
            continue;
        }
        int id1 = calcid(1, n, 1, st + 1);

        it = S.lower_bound(pi(st + 1, 0));
        int id2 = 0;
        if(it != S.begin()) {
            it --;
            pi ab = *it;
            if(ab.first == st) id2 = ab.second;
        }

        int stid;
        if(id1 < id2) stid = id2;
        else {
            if(Mx(id, id1, 1, n, 1) < st) stid = id2;
            else {
                int s = id;
                int e = id1 + 1;
                while(e - s > 1) {
                    int mid = (s + e) >> 1;
                    if(Mx(mid, id1, 1, n, 1) < st) e = mid;
                    else s = mid;
                }
                if(id2 > s) stid = id2;
                else stid = s;
            }
        }
        if(st == xx) {
			stid = Id;
		}
        printf("%d ", stid);
        pi ab = pi(ti[stid], stid);
        S.erase(ab);
        xx = ti[i];
        Id = i;
        ab = pi(ti[i], i);
        S.insert(ab);
        ans = st1 + ti[i];
        cha(stid + 1, i - 1, 1, n, 1, 0, -st);
        cha(stid, stid, 1, n, 1, -ti[stid], inf);
        cha(i, i, 1, n, 1, ti[i], -inf + st1 - l);
    }
    puts("");
    return 0;
}