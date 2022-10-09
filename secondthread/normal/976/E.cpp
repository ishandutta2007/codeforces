#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Monster {
	ll hp, damage;
	bool usedB=false;
	Monster(ll hp, ll damage): hp(hp), damage(damage) {}	

	bool operator<(const Monster &o) const {
		int me=hp-damage;
		int him=o.hp-o.damage;
		return me>him;
	}
};

int main() {
	int n, aSpells, bSpells; cin>>n>>aSpells>>bSpells;
	vector<Monster> monsters; monsters.reserve(n);
	for (int i=0; i<n; i++) {
		int hp, d; cin>>hp>>d;
		monsters.emplace_back(hp, d);
	}
	sort(monsters.begin(), monsters.end());
	ll baseSum=0;
	ll lastBenefit=0;
	for (int i=0; i<n; i++) {
		if (i<bSpells) {
			lastBenefit=0;
			if (monsters[i].hp>monsters[i].damage) {
				monsters[i].usedB=true;
				lastBenefit=monsters[i].hp-monsters[i].damage;
			}
		}
		baseSum+=monsters[i].usedB?monsters[i].hp:monsters[i].damage;
	}
	//cout<<baseSum<<endl;
	ll aMultiplier=1<<aSpells;
	ll best=baseSum;
	if (bSpells>0)  {
		for (int i=0; i<n; i++) {
			if (monsters[i].usedB)
				best=max(best, baseSum-monsters[i].hp+monsters[i].hp*aMultiplier);
			else
				best=max(best, baseSum-monsters[i].damage-lastBenefit+monsters[i].hp*aMultiplier);
		}
	}
	cout<<best<<'\n';
	return 0;
}