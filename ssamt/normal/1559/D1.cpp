#include <stdio.h>
#include <stdlib.h>
#include <vector>

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;
		std::vector< std::vector<int> > con;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
            for(i=0; i<n; i++) {
                std::vector<int> e(n, 0);
                con.push_back(e);
                con[i][i] = 1;
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
			a[j].push_back(i);
			int k, l;
			std::vector<int> al, bl;
			for(k=0; k<n; k++) {
				if(con[i][k]) {
					al.push_back(k);
				}
			}
			for(k=0; k<n; k++) {
				if(con[j][k]) {
					bl.push_back(k);
				}
			}
			for(k=0; k<al.size(); k++) {
				for(l=0; l<bl.size(); l++) {
					con[al[k]][bl[l]] = 1;
					con[bl[l]][al[k]] = 1;
				}
			}
		}
};

int main() {
	int h, i, j;
	int n, m1, m2;
	char s[100];
	int u, v;
    scanf("%d %d %d", &n, &m1, &m2);
	AdjGraph a(n), b(n);
    for(i=0; i<m1; i++) {
    	scanf("%d %d", &u, &v);
    	a.add(u-1, v-1);
	}
    for(i=0; i<m2; i++) {
    	scanf("%d %d", &u, &v);
    	b.add(u-1, v-1);
	}
	int added = 0;
	int* node[n];
	while(1) {
		int found = 0;
		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++) {
				if(!a.con[i][j] && !b.con[i][j]) {
					found = 1;
					a.add(i, j);
					b.add(i, j);
					node[added] = (int*)malloc(2*4);
					node[added][0] = i;
					node[added][1] = j;
					added++;
					//printf("%d %d\n", i, j);
				}
			}
		}
		if(!found) {
			break;
		}
	}
	printf("%d\n", added);
	for(i=0; i<added; i++) {
		printf("%d %d\n", node[i][0]+1, node[i][1]+1);
	}
}