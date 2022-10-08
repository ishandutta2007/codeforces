#include <bits/stdc++.h>

using namespace std;

bool match(vector<vector<int> > &target, vector<vector<int> > &current) {
	int w=target.size(), h=target[0].size();
	for (int x=0; x<w; x++)
		for (int y=0; y<h; y++)
			if (target[x][y]!=current[x][y]) return false;
	return true;
}

vector<int> xs, ys;

void placeLine(vector<vector<int> > &current, int x1, int y1, int x2, int y2, int color) {
	xs.push_back(x1+1);
	ys.push_back(y1+1);
	xs.push_back(x2+1);
	ys.push_back(y2+1);
	for (int x=x1; x<=x2; x++) {
		for (int y=y1; y<=y2; y++) {
			current[x][y]=color;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T; cin>>T;
	while (T--) {
		xs.clear(); ys.clear();
		int h, w; cin>>h>>w;
		vector<vector<int> > target, current;
		for (int i=0; i<w; i++) {
			target.push_back(vector<int>());
			current.push_back(vector<int>());
			for (int j=0; j<h; j++) {
				target[i].push_back(-1);
				current[i].push_back(-1);
			}
		}
		int maxPlaced=-1;
		int filledX=0, filledY=0;
		for (int y=0; y<h; y++) {
			string line; cin>>line;
			for (int x=0; x<w; x++) {
				if (line[x]=='.') continue;
				target[x][y]=line[x]-'a';
				maxPlaced=max(maxPlaced, target[x][y]);
				if (maxPlaced==target[x][y]) {
				filledX=x;
				filledY=y;
				}
			}
		}

		bool possible=true;
		for (int toPlace=0; toPlace<=maxPlaced; toPlace++) {
			int minX=w, minY=h, maxX=-1, maxY=-1;
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (target[x][y]==toPlace) {
						minX=min(minX, x);
						maxX=max(maxX, x);
						minY=min(minY, y);
						maxY=max(maxY, y);
					}
				}
			}
			if (maxX==-1) {
				placeLine(current, filledX, filledY, filledX, filledY, toPlace);
			}
			else if (maxX!=minX&&maxY!=minY) {
				possible=false;
			}
			else {
				placeLine(current, minX, minY, maxX, maxY, toPlace);
			}
		}
		if (possible&&match(target, current)) {
			cout<<"YES\n"<<xs.size()/2<<'\n';
			for (int i=0; i<xs.size(); i+=2) {
				cout<<ys[i]<<" "<<xs[i]<<" "<<ys[i+1]<<" "<<xs[i+1]<<'\n';
			}
		}
		else {
			cout<<"NO\n";
		}

	}


	return 0;
}