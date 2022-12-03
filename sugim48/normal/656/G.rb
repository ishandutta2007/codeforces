n,m,t=gets.split.map(&:to_i)
a=Array.new(n){gets}
kitten=0
m.times{|j|cnt=0
n.times{|i|cnt+=1 if a[i][j]=="Y"}
kitten+=1 if cnt>=t}
p kitten