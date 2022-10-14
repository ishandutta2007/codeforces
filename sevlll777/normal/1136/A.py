hop = []
for i in range(int(input())):
    a, b = map(int, input().split())
    hop.append(b)
k = int(input())
for i in range(len(hop)):
    if k <= hop[i]:
        print(len(hop) - i)
        break