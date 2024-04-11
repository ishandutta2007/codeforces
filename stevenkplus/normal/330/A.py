I=input
n,m = map(int,I().split())
g = [I() for i in range(n)]
print(n*m-len([1 for i in g if i.count('S')])*len([1 for i in zip(*g) if i.count('S')]))