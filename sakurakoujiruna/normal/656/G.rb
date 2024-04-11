n,m,k=gets.split.map{|x|x.to_i}
a=Array.new(m,0)
n.times do
	s=gets
	m.times do |i|
		a[i]+=1 if s[i]=='Y'
	end
end
p a.count{|x|x>=k}

kitten=0