#from math import *
from sys import *
from decimal import *

getcontext().prec = 100

#in_ = open("input.txt","r")
#out_ = open("output.txt","w")

class graph:
    def __init__(self, sz, is_oriented):
        self.g = []
        for i in range(sz):
            self.g.append(set())
        self.size = sz
        self.oriented = is_oriented
    def __str__(self):
        out = "size: {0}\n".format(self.size)
        for i in range(self.size):
            out += "{0} -> ".format(i+1)
            for j in self.g[i]:
                out += str(j)
            out += "\n"
        return out
    def addvertex(self):
        self.g.append(set())
    def addedge(self, u, v):
        self.g[u].add(v)
        if self.oriented:
            self.g[v].add[u]
    def neighbours(self, v):
        return self.g[v]
    def is_neighbour(self, u, v):
        return (v in self.g[u]) #addvertex,addedge,is_neighbour,neighbours
class dsu:
    def __init__(self, number):
        self.par = [z for z in range(number + 1)]
        self.rk = [0] * (number + 1) 
        self.size = number
    def find(self, a):
        if a == self.par[a]:
            return a
        self.par[a] = self.find(self.par[a])
        return self.par[a]
    def unite(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if(a == b):
            return 0
        if self.rk[a] < self.rk[b]:
            a,b = b,a
        self.par[b] = a
        if(self.rk[a] == self.rk[b]):
            self.rk[a] += 1
        return 1
    def create(self):
        self.size += 1
        self.par.append(self.size)
        self.rk.append(0) #find,create,unite

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a
def lcm(a,b):

    return a*b//gcd(a,b)


n = int(input())
cnt = dict()
st = set()
arr=[]
for i in range(n):
    k = int(input())
    if not cnt.get(k):
        cnt[k] = 1
    cnt[k]+=1
    st.add(k)
    arr.append(k)
if len(st) != 2:
    print("NO")
    exit(0)
for lol in arr:
    if cnt[lol] != cnt[arr[0]]:
        print("NO")
        exit(0)
print("YES")
for i in st:
    print(i, end = ' ')