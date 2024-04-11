r,c=[int(i) for i in input().split()]
for i in range(r-1):
    input()
s=input()
for i in range(c):
    s=s.replace('BB','B')
print(s.count('B'))