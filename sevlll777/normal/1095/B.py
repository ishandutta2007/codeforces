n = int(input())
a = list(map(int, input().split()))
max12 = [-float("inf"), -float("inf")]
min12 = [float("inf"), float("inf")]
for u in a:
    if u > min(max12):
        max12[max12.index(min(max12))] = u
    if u < max(min12):
        min12[min12.index(max(min12))] = u
print(min(min(max12) - min(min12), max(max12) - max(min12)))