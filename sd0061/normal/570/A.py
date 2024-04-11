n , m = map(int , raw_input().split(' '))
p = [0 for i in range(n)]
for i in range(m):
    s = map(int , raw_input().split(' '))
    p[s.index(max(s))] += 1
print p.index(max(p)) + 1