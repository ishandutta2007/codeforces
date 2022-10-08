input()
a=map(int,raw_input().split())
print max([a.count(i)for i in a]),len(set(a))