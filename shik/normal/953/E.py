_ = int(raw_input())
a = map(int, raw_input().split())
b = []
for x in a:
    b.append(x)
    while len(b) >= 2 and b[-2] == b[-1]:
        b.pop()
        b[-1] += 1
print len(b)
print ' '.join(map(str, b))