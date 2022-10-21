#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll INF = (ll)2e18;

struct P {
    ll l, r, t;

    void read() {
        cin >> l >> r >> t;
    }
} p[N];

struct Job {
    ll r, len;
    bool const operator < (const Job &j2) const {
        return len < j2.len;
    }
    bool const operator > (const Job &j2) const {
        return len > j2.len;
    }
};


int n;
ll next_end_time = -1, job_len = -1;
ll curtime = 0;

multiset<Job> best;
ll res = 0;

void elim(ll moment) {
    while(!best.empty()) {
        auto p = *best.begin();
        ll final_end_time = p.r;
        job_len = p.len;
//        cout << "Start considering job: " << " end: " << p.r << ", " << "len: " << job_len << endl;

        ll take = (min(moment, final_end_time) - curtime) / job_len;
        if(take >= 0) {
            res += take;
//            cout << "Taking: " << t<< endl;
            curtime += take * job_len;
        }
        if(final_end_time - curtime < job_len) {
//            cout << final_end_time << ", " << curtime << ", " << job_len << endl;
            job_len = -1;
            best.erase(best.begin());
            continue;
        }
        next_end_time = curtime + job_len;
//        cout << "Good considering job: " << " end: " << p.r << ", " << "len: " << job_len << endl;
//        cout << "Elim: setting the next_end_time to be " << next_end_time << endl;

        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) p[i].read();
    sort(p, p + n, [](const P &p1, const P &p2) {
        return p1.l < p2.l;
    });

    for(int i = 0; i < n; i++) {
        if(job_len != -1 && next_end_time <= p[i].l) {
//            cout << "Finishing " << job_len << endl;
            res ++;
            curtime = next_end_time;
            job_len = -1;
            elim(p[i].l);
        }
        best.insert(Job{p[i].r, p[i].t});
        if(job_len == -1 || p[i].l + p[i].t < next_end_time) {
            next_end_time = p[i].l + p[i].t;
            job_len = p[i].t;
//            cout << "Seeting to " << i << " " << job_len << endl;
        }
    }
//    cout << res << endl;
//    cout << curtime << endl;
    if(job_len != -1) {
        res ++;
        curtime = next_end_time;
        job_len = -1;
        elim(INF);
    }

    cout << res << endl;
}