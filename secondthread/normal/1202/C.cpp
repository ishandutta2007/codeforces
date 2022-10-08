#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int minXTime, maxXTime, minYTime, maxYTime;

ll eval(string input, int pos, char toInsert) {
	if (pos!=-1&&pos>input.size()) return 1e18;
	if (pos!=-1)
		input.insert(input.begin()+pos, toInsert);
	else
		minXTime=maxXTime=minYTime=maxYTime=1e8;
	ll x=0, y=0, minX=0, maxX=0, minY=0, maxY=0;
	string moves="WASD";
	int dx[]={0, -1, 0, 1}, dy[]={-1, 0, 1, 0};
	int time=0;
	for (char c:input) {
		for (int i=0; i<4; i++) {
			if (moves[i]==c) {
				x+=dx[i];
				y+=dy[i];
				if (pos==-1) {
					if (x<minX) minXTime=time;
					if (x>maxX) maxXTime=time;
					if (y<minY) minYTime=time;
					if (y>maxY) maxYTime=time;
				}
				minX=min(minX, x);
				maxX=max(maxX, x);
				minY=min(minY, y);
				maxY=max(maxY, y);
			}
		}
		time++;
	}
	return (maxX-minX+1)*(maxY-minY+1);
}

int main() {
	int T; cin>>T;
	while (T--) {
		string input; cin>>input;
		ll ans=eval(input, -1, 'W');
		ans=min(ans, eval(input,minXTime, 'D'));
		ans=min(ans, eval(input,maxXTime, 'A'));
		ans=min(ans, eval(input,minYTime, 'S'));
		ans=min(ans, eval(input,maxYTime, 'W'));
		cout<<ans<<'\n';
	}

	return 0;
}