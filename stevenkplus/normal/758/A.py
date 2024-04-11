n = int(raw_input())
ar = map(int, raw_input().split())
print -(sum(ar) - max(ar) * len(ar))